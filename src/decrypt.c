
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
beaufort_decrypt (const char *src, const char *key, char **mat) {
  char *dec = NULL;
  char ch = 0;
  char ct = 0;
  size_t ksize = 0;
  size_t size = 0;
  size_t rsize = 0;
  size_t len = 0;
  int i = 0;
  int x = 0;
  int y = 0;
  int j = 0;
  int needed = 1;

  if (NULL == dec) { return NULL; }

  if (NULL == mat) {
    mat = beaufort_tableau(BEAUFORT_ALPHA);
  }

  ksize = (size_t) strlen(key);
  len = (size_t) strlen(src);
  rsize = (size_t) strlen(mat[0]);
  dec = (char *) malloc(sizeof(char) * len + 1);

  for (; (ch = src[i]); ++i) {
    needed = 1;

    for (y = 0; y < rsize; ++y) {
      if (ch == mat[y][0]) { needed = 1; break; }
      else { needed = 0; }
    }

  }

  dec[size] = '\0';

  return dec;
}
