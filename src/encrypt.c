
/**
 * `encrypt.c' - libbeaufort
 *
 * copyright (c) 2014 joseph werle <joseph.werle@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <beaufort.h>

char *
beaufort_encrypt (const char *src, const char *key, char **mat) {
  char *enc = NULL;
  char ch = 0; // current char
  char k = 0; // key index
  size_t ksize = 0;  // key size
  size_t size = 0; // encrypted text size
  size_t len = 0; // source size
  size_t rsize = 0; // row size
  int i = 0; // source index
  int x = 0; // mat row index
  int y = 0; // mat column index
  int j = 0; // key modulo
  int needed = 1; // needs encryption predicate

  if (NULL == mat) {
    mat = beaufort_tableau(BEAUFORT_ALPHA);
  }

  ksize = (size_t) strlen(key);
  len = (size_t) strlen(src);
  rsize = (size_t) strlen(mat[0]);
  enc = (char *) malloc(sizeof(char) * len + 1);

  for (; (ch = src[i]); ++i) {
    // reset
    needed = 1;
    x = 0; y = 0;

    // column with `ch' at top
    for (x = 0; x < rsize; ++x) {
      if (ch == mat[y][x]) { needed = 1; break; }
      else { needed = 0; }
    }

    if (0 == needed) {
      enc[size++] = ch;
      continue;
    }

    // determine char in `key'
    k = key[(j++) % ksize];

    // find row in column with `key[k]'
    for (y = 0; y < rsize; ++y) {
      if (k == mat[y][x]) { needed = 1; break; }
      else { needed = 0; }
    }

    if (0 == needed) {
      enc[size++] = ch;
      j--;
      continue;
    }

    enc[size++] = mat[y][0];
  }

  enc[size] = '\0';

  return enc;
}
