#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

#include <memory.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include "service_pi_socket.h"

/*
 * service_pi_socket.c
 *
 * thread for every pi that connects to the server
 *
 * Author: dla507
 */

#define buffer_size 1024

//The number of characters that make up a token/id
#define TOKEN_LEN 64
#define ID_LEN 16

int service_pi_socket (const int s, const char *const addr) {
  fprintf(stderr, "New connection from %s.\n", addr);

  char buffer[buffer_size];
  ssize_t nbytes;

  connection_state_t conn_state = initial;

  printf ("new connection from %s\n", tag);

  while (conn_state != closed && (nbytes = read (s, buffer, buffer_size)) > 0) {
    switch(conn_state) {
    case initial:
      if (nbytes == TOKEN_LEN) {
	//Check database for token
      } else if (nbytes == ID_LEN) {
	//Go into "pairing mode"
      } else {
	fprintf(stderr, "Unexpected data sent by %s. Closing connection.\n",
		addr);
	conn_state = closed;
      }
      break;
    case connected:
      //Process data and publish to database
      break;
    }
  }
  
  if (bytes != 0) {
    fprintf(stderr, "Unorderly close with %s.\n", addr);
    close(s);
    return -1;
  } else {
    printf ("Connection from %s closed.\n", tag);
    close (s);
    return 0;
  }
}
