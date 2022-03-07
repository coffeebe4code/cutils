#pragma once
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>

#define lifetime(var_name, type, size, _body_)                                 \
  do {                                                                         \
    type var_name = malloc(sizeof(type) * size);                               \
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
