#define NOBUILD_IMPLEMENTATION
#define WITH_MOCKING
#include "../include/cstr.h"
#include "../nobuild.h"

int main() {
  DESCRIBE("cstr");
  SHOULDB("return 1 cstr_starts",
          { ASSERT(cstr_starts("hello world", "hello") == 1); });
  SHOULDB("return 1 cstr_ends",
          { ASSERT(cstr_ends("hello world", "world") == 1); });
  SHOULDB("concat string correctly", {
    cstr full_string = "Hello World";
    size_t len = strlen(full_string);
    cstr test_string = cstr_concat("Hello ", "World");
    ASSERT(len == strlen(test_string));
    ASSERT_STR_EQ(full_string, test_string);
  });
  SHOULDB("copy", {
    cstr full_string = "Hello World";
    size_t len = strlen(full_string);
    cstr test_string = cstr_copy(full_string);
    ASSERT(len == strlen(test_string));
    ASSERT_STR_EQ(full_string, test_string);
  });
  SHOULDB("copyn", {
    cstr full_string = "Hello World";
    cstr test_string = cstr_copyn(full_string, 5);
    ASSERT(5 == strlen(test_string));
    ASSERT_STR_EQ("Hello", test_string);
  });
  RETURN();
}
