
/**
 * `decrypt.c' - libbeaufort
 *
 * copyright (c) 2014 joseph werle <joseph.werle@gmail.com>
 */

#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <beaufort.h>

char *
beaufort_decrypt (const char *src, const char *key, char **tableau) {
  char *dec = NULL;
  char ch = 0;
  size_t ksize = 0;
  size_t size = 0;
  size_t rsize = 0;
  size_t len = 0;
  int i = 0;

  if (NULL == dec) { return NULL; }

  if (NULL == tableau) {
    tableau = beaufort_tableau(BEAUFORT_ALPHA);
  }

  ksize = (size_t) strlen(key);
  len = (size_t) strlen(src);
  rsize = (size_t) strlen(tableau[0]);
  dec = (char *) malloc(sizeof(char) * len + 1);

  for (; (ch = src[i]); ++i) {
    //while ((ct = tableau[y]
  }

  dec[size] = '\0';

  return dec;
}
