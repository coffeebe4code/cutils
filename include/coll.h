#pragma once

#define coll_create(type)                                                      \
  typedef struct coll_##type coll_##type;                                      \
  struct coll_##type {                                                         \
    coll_##type *elems;                                                        \
    size_t len;                                                                \
  };                                                                           \
  coll_##type coll_##type##_new
