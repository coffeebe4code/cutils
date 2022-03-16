#pragma once
#include <stdlib.h>

typedef const char *cstr;
typedef struct Acstr cstr_t;
struct Acstr {
  cstr val;
  size_t len;
};
/// returns 1 if the cstr starts with prefix, 0 otherwise.
int cstr_starts(cstr val, cstr prefix);
/// returns 1 if the cstr ends with postfix, 0 otherwise.
int cstr_ends(cstr val, cstr postfix);
/// appends the append variable cstr to the value.
cstr cstr_concat(cstr val, cstr append);
/// clones the provided cstr.
cstr cstr_copy(cstr to_copy);
/// clones the provided cstr given a len of number of characters.
cstr cstr_copyn(cstr to_copy, size_t len);
