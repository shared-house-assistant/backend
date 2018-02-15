#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <netinet/in.h>

/*
 * make_printable_address.c
 *
 * Used to turn a sockaddr_in6 into a human readable address.
 *
 * Author: dla507
 */

char *make_printable_address (const struct sockaddr_in6 *const addr,
			const socklen_t addr_len,
			char *const buffer,
			const size_t buffer_size) {
  char printable[INET6_ADDRSTRLEN];
  
  if (inet_ntop (addr->sin6_family, &(addr->sin6_addr),
		 printable, sizeof (printable)) == printable) {
    snprintf (buffer, buffer_size, "%s port %d",
	      printable, ntohs (addr->sin6_port));
  } else {
    fprintf(stderr, "Error parsing IP address.\n");
    snprintf (buffer, buffer_size, "unknown");
  }

  return strdup (buffer);
}

  
