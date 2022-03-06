#define NOBUILD_IMPLEMENTATION
#define WITH_MOCKING
#include "../include/lambda.h"
#include "../nobuild.h"

void test_max() {
  lambda(int, max, (int x, int y), { return x > y ? x : y; });
  ASSERT(max(2, 1) == 2);
}

void test_l_max() {
  l_max(int);
  ASSERT(max(2, 1) == 2);
}

void test_find() {
  lambda(int *, find, (int x[], int c, int y), {
    for (int i = 0; i < c; i++) {
      if (x[i] == y) {
        return &x[i];
      }
    }
    return NULL;
  });
  int array[5] = {0, 1, 2, 3, 4};
  ASSERT(*find(array, 5, 4) == 4);
}

void test_l_find() {
  l_find(int *, int, int);
  int array[5] = {0, 1, 2, 3, 4};
  ASSERT(*find(array, 5, 4) == 4);
}

void test_l_find_str() {
  l_find_stridx();
  const char *array[3] = {"hello", "world", "test"};

  ASSERT(find_stridx(array, 3, "world") == 1ul);
}

int main() {
  DESCRIBE("lambda");
  SHOULDF("build max lambda and get max", test_max);
  SHOULDF("use l_max and get max", test_l_max);
  SHOULDF("build find lambda and get ptr", test_find);
  SHOULDF("use l_find_stridx and get index", test_l_find_str);
  SHOULDF("use l_find and get ptr", test_l_find);
  RETURN();
}
