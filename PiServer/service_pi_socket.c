#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <memory.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include "service_client_socket.h"

/*
 * service_pi_socket.c
 *
 * thread for every pi that connects to the server
 *
 * Author: dla507
 */

int service_pi_socket (const int s, const char *const addr) {
  fprintf(stderr, "New connection from %s.\n", addr);

  /*
    Secure connection
    -authenticate server
    -setup session key (Diffe-Hellman?)

    run identify protocol
   */
}
