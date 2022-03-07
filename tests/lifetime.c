#define NOBUILD_IMPLEMENTATION
#define WITH_MOCKING
#include "../include/lifetime.h"
#include "../nobuild.h"

int main() {
  DESCRIBE("lifetime");
  SHOULDB("free the string", {
    char *my_string;
    outer_lifetime(my_string, char *, 1, {
      memcpy(my_string, "hello", 5);
      ASSERT_STR_EQ(my_string, "hello");
    });
    ASSERT(my_string == NULL);
  });
  RETURN();
}
