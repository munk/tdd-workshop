#include <stdio.h>
#include "bignum.h"

int main(int argc, char* argv[]) {
  char* a = argv[1];
  char* b = argv[2];
  char* c = add(a, b);
  printf("%s + %s = %s\n", a, b, c);
  return 0;
}
