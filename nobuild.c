#define NOBUILD_IMPLEMENTATION
#define CFLAGS "-Wall", "-Werror", "-std=c11"
#define DCOMP "-g", "-O0", "-fsanitize=address,", "undefined"
#include "./nobuild.h"

int main(int argc, char **argv) {
  BOOTSTRAP(argc, argv);
  return 0;
}
