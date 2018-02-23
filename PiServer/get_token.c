#include <bsd/stdlib.h>
#include <stdio.h>
#include <string.h>

#include "get_token.h"

/*
 * get_token.c
 *
 * Used to get a cryptographically secure random hex string to be used as a
 * token for login to pi server.
 *
 * Author: dla507
 */


//The size, in bytes, of the tokens that will be created.
#define TOKEN_LEN 32
#define TOKEN_HEX_LEN (TOKEN_LEN * 2)

#define random_byte() (arc4random_uniform(256))

char *get_token() {
  char *token_hex = malloc(TOKEN_HEX_LEN + 1);

  for(int i=0; i<TOKEN_HEX_LEN; i+=2) {
    sprintf(token_hex+i, "%02X", random_byte());
  }
  
  return token_hex;
}
