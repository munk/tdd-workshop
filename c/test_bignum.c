#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testrunner.h"
#include "bignum.h"

int id(int x) {
  return x;
}

bool test_plus_n_is_n() {
  char* expected = "1";
  char* actual = add("1", "0");
  return compare_strings(expected, actual);
}


int main(int argc, char** argv) {
  register_test("zero plus n is n", &test_plus_n_is_n);  
  run_tests();
  return 0;
}
