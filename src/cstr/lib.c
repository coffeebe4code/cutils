#include "../../include/cstr.h"
#include <stdio.h>
#include <string.h>

int cstr_starts(cstr val, cstr prefix) {
  const size_t cstr_len = strlen(val);
  const size_t prefix_len = strlen(prefix);
  return prefix_len <= cstr_len && strncmp(val, prefix, prefix_len) == 0;
}

int cstr_ends(cstr val, cstr postfix) {
  const size_t cstr_len = strlen(val);
  const size_t postfix_len = strlen(postfix);
  return postfix_len <= cstr_len &&
         strcmp(val + cstr_len - postfix_len, postfix) == 0;
}

cstr cstr_concat(cstr val, cstr append) {
  size_t val_len = strlen(val);
  size_t append_len = strlen(append);

  char *result = calloc(val_len + append_len, sizeof(char));
  memcpy(result, val, val_len);
  memcpy(result + val_len, append, append_len);
  result[val_len + append_len] = '\0';
  return result;
}

cstr cstr_copy(cstr to_copy) {
  size_t len = strlen(to_copy);

  char *result = calloc(len, sizeof(char));
  memcpy(result, to_copy, len);
  result[len] = '\0';
  return result;
}

cstr cstr_copyn(cstr to_copy, size_t len) {
  char *result = calloc(len, sizeof(char));
  memcpy(result, to_copy, len);
  result[len] = '\0';
  return result;
}
