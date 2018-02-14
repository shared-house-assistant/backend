#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_listening_socket.h"
#include "service_gate_socket.h"

const int DEFAULT_PORT = 101010; 

/*
 * main.c
 *
 * Used to start up the main raspberry pi server
 *
 * Author: dla507
 */

int main(int argc, char **argv) {
  if (argc == 1) {
    fprintf(stderr, "Starting pi server on default port %d.\n", DEFAULT_PORT);
    setup_server(DEFAULT_PORT);
  } else if (argc == 2) {
    int port = strtol (argv[1], &endp, 10);

    if (*endp != '\0') {
      fprintf(stderr, "Error, %s is not a number.\n", argv[1]);
      exit(1);
    }

    if (port < 0 || port > 65535) {
      fprintf(stderr, "Error, invalid port number.\n");
      exit(1);
    }

    setup_server(port);
    
  } else {
    fprintf(stderr, "Error, no arguments or just port number required.\n");
    exit(1);
  }

  exit(0);
}

void setup_server(const int port) {
  int soc = get_listening_socket(port);

  if (soc < 0) {
    fprintf(stderr, "Error getting listening socket.\n");
    exit(1);
  } 

  if (service_gate_socket(soc) != 0) {
    fprintf(stderr, "Error processing socket.\n");
    exit(1);
  }

  exit(0);
}
