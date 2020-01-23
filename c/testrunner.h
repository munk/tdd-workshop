#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)
#define genfunc CONCAT(test_func, __COUNTER__)
#define genpred CONCAT(pred_func, __COUNTER__)

typedef bool (*test_t)(void);
#define TEST(name, test_func) void genfunc () { printf("Test: %s\n", name); (test_func() == true) ? printf("PASS"): printf("FAIL");}
#define TEST_COUNT 32
int test_index = 0;

test_t tests[TEST_COUNT] =
{
   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,
   NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL,		    
};

char* names[TEST_COUNT];

int idx = 0;

void add_test(test_t test) {
  tests[idx++] = test;
}

void color_red() {
  printf("\033[1;31m");
}

void color_green() {
  printf("\033[1;32m");  
}

void color_reset() {
  printf("\033[0m");
}

void run_tests() {
  int k = 0;
  test_t test = tests[k];
  while(test != NULL) {
    printf("Test %d of %d %s\n", k+1, test_index, names[k]);
    bool result = test();
    if (result) {
      color_green();
      printf("PASS!\n");
      color_reset();
    } else {
      color_red();
      printf("FAIL!\n");
      color_reset();
    }
    test = tests[++k];
  }
}

void register_test(char* name, test_t t) {
  int i = test_index;
  tests[i] = t;
  names[i] = name;
  test_index++;
}

bool compare_strings(char* a, char* b) {
  printf("Expected %s. Result was: %s\n", a, b);
  return strncmp(a, b, 128) == 0;
}
