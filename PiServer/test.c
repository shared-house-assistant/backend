#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "get_token.h"

int main(int argc, char **argv) {
  char *token = get_token();
  free(token);
  exit(0);
}

