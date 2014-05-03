
/**
 * `test.c' - libbeaufort
 *
 * copyright (c) 2014 joseph werle <joseph.werle@gmail.com>
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ok.h>
#include <beaufort.h>

#define test(name, e) {                   \
  if (!(e)) {                             \
    fprintf(stderr, "failed: %s\n", # e); \
    return 1;                             \
  } else {                                \
    ok(name);                             \
  }                                       \
}

#define texpect(fn, a, b) {              \
  printf("(%s): ", # fn);                \
  test(a, 0 == strcmp(fn(a, ALPHA), b)); \
}

static int
test_encrypt ();

static int
test_decrypt ();

static int
test_tableau ();

int
main (void) {
  test("encrypt suite", 0 == test_encrypt());
  test("decrypt suite", 0 == test_decrypt());
  test("tableau suite", 0 == test_tableau());
  ok("beaufort");
  return 0;
}

static int
test_encrypt () {
  char *enc = NULL;

  // kinkajous are awesome
  // qsnqarmgi ajw aewimow
  enc = beaufort_encrypt("kinkajous are awesome", "monkey", NULL);
  assert(enc);
  assert(0 == strcmp(enc, "cgaaepyuv knu msjsqmi"));

  enc = beaufort_encrypt("the \nbig \nlebowski", "goodman", NULL);
  assert(enc);
  assert(0 == strcmp(enc, "nhk \nceu \nccnahuqf"));

  enc = beaufort_encrypt("d4nc3 t0 th3 mus!c :D", "groove", NULL);
  assert(enc);
  assert(0 == strcmp(enc, "d4em3 v0 cx3 uxw!m :D"));

  return 0;
}

static int
test_decrypt () {
  return 0;
}

static int
test_tableau () {

#define tfree(m) {                    \
  for (int i = 0; m[i]; ++i) {        \
    if (NULL != m[i]) { free(m[i]); } \
  }                                   \
}

  {
    char **mat = beaufort_tableau(BEAUFORT_ALPHA);
    assert(mat);


    tfree(mat);
  }


  {
    char **mat = beaufort_tableau("abc");
    assert(mat);

    assert('a' == mat[0][0]);
    assert('b' == mat[0][1]);
    assert('c' == mat[0][2]);

    assert('b' == mat[1][0]);
    assert('c' == mat[1][1]);
    assert('a' == mat[1][2]);

    assert('c' == mat[2][0]);
    assert('a' == mat[2][1]);
    assert('b' == mat[2][2]);

    tfree(mat);
  }

#undef tfree

  return 0;
}
