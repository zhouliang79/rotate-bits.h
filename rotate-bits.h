

#ifndef __ROTATE_DEFS_H
#define __ROTATE_DEFS_H

#define C64V(v) (unsigned long long)(v)

#define U8V(v) ((unsigned char)(v) & 0xFFU)
#define U16V(v) ((unsigned short)(v) & 0xFFFFU)
#define U32V(v) ((unsigned long)(v) & 0xFFFFFFFFU)
#define U64V(v) ((unsigned long long)(v) & 0xFFFFFFFFFFFFFFFFU)

#ifdef _MSC_VER

#include <stdlib.h>

#define ROTL32(v, n) _rotl((v), (n))
#define ROTL64(v, n) _rotl64((v), (n))

#define ROTR32(v, n) _rotr((v), (n))
#define ROTR64(v, n) _rotr64((v), (n))

#else

#define ROTL32(v, n) \
  (U32V((v) << (n)) | ((v) >> (32 - (n))))

// tests fail if we don't have this cast...
#define ROTL64(v, n) \
  (U64V((unsigned long long)(v) << (n)) | ((v) >> (64 - (n))))

#define ROTR32(v, n) ROTL32(v, 32 - (n))
#define ROTR64(v, n) ROTL64(v, 64 - (n))

#endif

#define ROTL8(v, n) \
  (U8V((v) << (n)) | ((v) >> (8 - (n))))

#define ROTL16(v, n) \
  (U16V((v) << (n)) | ((v) >> (16 - (n))))

#define ROTR8(v, n) ROTL8(v, 8 - (n))
#define ROTR16(v, n) ROTL16(v, 16 - (n))

#endif
