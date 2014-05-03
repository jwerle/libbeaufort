
/**
 * `beaufort.h' - libbeaufort
 *
 * copyright (c) 2014 joseph werle <joseph.werle@gmail.com>
 */

#ifndef BEAUFORT_H
#define BEAUFORT_H 1

#if __GNUC__ >= 4
# define BEAUFORT_EXTERN __attribute__((visibility("default")))
#else
# define BEAUFORT_EXTERN
#endif

/**
 * Default beaufort alphabet
 */

#ifndef BEAUFORT_ALPHA
#define BEAUFORT_ALPHA \
  "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
//#define BEAUFORT_ALPHA "abcdefghijklmnopqrstuvwxyz"
#endif

/**
 * beaufort version
 */

#ifndef BEAUFORT_VERSION
#define BEAUFORT_VERSION "1" // default
#endif

/**
 * Encrypts plaintext using the beaufort
 * cipher and a 26x26 alphabet table
 */

BEAUFORT_EXTERN char *
beaufort_encrypt (const char *, const char *, char **);

/**
 * Decrypts plaintext using the beaufort
 * cipher and a 26x26 alphabet table
 */

BEAUFORT_EXTERN char *
beaufort_decrypt (const char *, const char *, char **);

/**
 * Constructs a tableau of rows
 * and columns from a given alphabet
 */

BEAUFORT_EXTERN char **
beaufort_tableau (const char *);

#endif

