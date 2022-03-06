#define NOBUILD_IMPLEMENTATION
#define CFLAGS "-Wall", "-Werror", "-std=c11"

#include "./nobuild.h"

int main(int argc, char **argv) {
  FEATURE("lambda");
  LIB("lambda");
  BOOTSTRAP(argc, argv);
  return 0;
}
