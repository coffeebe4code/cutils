#pragma once
#include <stdlib.h>

#define lambda(ret_type, name, args, _body)                                    \
  ret_type(*name) args = ({ ret_type _ args _body _; })

#define l_max(types)                                                           \
  lambda(types, max, (types x, types y), { return x > y ? x : y; })

#define l_min(types)                                                           \
  lambda(types, max, (types x, types y), { return x < y ? x : y; })

#define l_find(ret_ptr_type, array_type, val_type)                             \
  lambda(ret_ptr_type, find, (array_type x[], size_t c, val_type val), {       \
    for (size_t i = 0; i < c; i++) {                                           \
      if (x[i] == val) {                                                       \
        return &x[i];                                                          \
      }                                                                        \
    }                                                                          \
    return NULL;                                                               \
  })

#define l_find_stridx()                                                        \
  lambda(size_t, find_stridx, (const char **x, size_t c, const char *val), {   \
    for (size_t i = 0; i < c; i++) {                                           \
      if (strcmp(x[i], val) == 0) {                                            \
        return i;                                                              \
      }                                                                        \
    }                                                                          \
    return -1;                                                                 \
  })
