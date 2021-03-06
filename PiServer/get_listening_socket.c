#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <memory.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "service_gate_socket.h"

/*
 * get_listening_socket.c
 *
 * Used to obtain a socket that is in the listening state
 *
 * Author: dla507
 */

int get_listening_socket(const int port) {
  fprintf(stderr, "Binding to port %d\n", port);
  struct sockaddr_in6 address;

  memset(&address, '\0', sizeof(address));
  address.sin6_family = AF_INET6;
  address.sin6_addr = in6addr_any;
  address.sin6_port = htons(port);

  int soc = socket(PF_INET6, SOCK_STREAM, 0);

  if (soc < 0) {
    fprintf(stderr, "Error creating socket.\n");
    return -1;
  }

  if (bind (soc, (struct sockaddr *) &address, sizeof(address)) != 0) {
    fprintf(stderr, "Error binding to socket.\n");
    return -1;
  }

  if (listen (soc, 5) != 0) {
    fprintf(stderr, "Error listening on socket.\n");
    return -1;
  }

  return soc;
}
