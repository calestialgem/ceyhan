#include "cey.h"

#include <stdio.h>

int main() {
  if (fprintf(stderr, "Hello, %s!\n", cey_debug_name()) < 0) {
    return -1;
  }
  return 0;
}
