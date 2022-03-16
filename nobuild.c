#define NOBUILD_IMPLEMENTATION
#define CFLAGS "-Wall", "-Werror", "-std=c11"

#include "./nobuild.h"

int main(int argc, char **argv) {
  FEATURE("lifetime");
  LIB("lifetime");
  BOOTSTRAP(argc, argv);
  return 0;
}
