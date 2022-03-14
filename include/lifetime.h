#pragma once
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>

// forwards
// macros
#define lifetime(var_name, type, size, _body_)                                 \
  do {                                                                         \
    type var_name = calloc(size, sizeof(type));                                \
    _body_;                                                                    \
    free(var_name);                                                            \
    var_name = NULL;                                                           \
  } while (0);

#define outer_lifetime(var_name, type, size, _body_)                           \
  do {                                                                         \
    var_name = calloc(size, sizeof(type));                                     \
    _body_;                                                                    \
    free(var_name);                                                            \
    var_name = NULL;                                                           \
  } while (0);

// for now, var_name must be unique across entire project
#define long_lifetime(var_name, type, size)                                    \
  size_t __##var_name##__ref_count = 0;                                        \
  int __##var_name##__index = 0;
