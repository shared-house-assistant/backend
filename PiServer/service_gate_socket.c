#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <memory.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <pthread.h>

#include "service_pi_socket.h"
#include "service_gate_socket.h"
#include "make_printable_address.h"

/*
 * service_gate_socket.c
 *
 * Used to accept new connections and run them in their own thread
 *
 * Author: dla507
 */

typedef struct client_info {
  int client;
  struct sockaddr_in6 address;
  socklen_t address_size;
} client_info_t;

static void *client_thread(void *data) {
  client_info_t *c_info = (client_info_t *) data;
  char buffer [INET6_ADDRSTRLEN + 32];
  char *printable;

  printable = make_printable_address (&(c_info->address),
				      c_info -> address_size,
				      buffer, sizeof(buffer));

  service_pi_socket(c_info->client, printable);

  free(printable);
  free(data);

  pthread_exit(0);
}

int service_gate_socket(const int s) {
  while(1) {
    client_info_t *c_info = malloc(sizeof (*c_info));

    if (c_info == 0) {
      fprintf(stderr, "Error on malloc.\n");
      exit(1);
    }

    c_info -> address_size = sizeof(c_info -> address);

    if ((c_info->client = accept (s, (struct sockaddr *) &(c_info -> address),
				  &(c_info -> address_size))) < 0) {
      fprintf(stderr, "Error accepting connection, continuing.\n");
    } else {
      pthread_t thread;

      if (pthread_create (&thread, 0, &client_thread, (void *) c_info) != 0) {
	fprintf(stderr, "Error creating client thread.\n");
	return -1;
      }

      if (pthread_detach (thread) != 0) {
	fprintf(stderr, "Error on pthread_detach, continuing.\n");
      }
    }
  }
  return -1;
}
