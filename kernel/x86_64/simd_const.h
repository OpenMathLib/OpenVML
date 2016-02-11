#ifndef __SIMD_CONST_H__
#define __SIMD_CONST_H__

#include <emmintrin.h>
#include <xmmintrin.h>
#include <pmmintrin.h>
#include <immintrin.h>

#include <openvml_config.h>

#ifndef ALIGN32_BEG
#define ALIGN32_BEG
#endif

#ifndef ALIGN32_END
#define ALIGN32_END __attribute__((aligned(32)))
#endif

#ifdef COMPILER_MSVC
#undef ALIGN32_BEG
#define ALIGN32_BEG __declspec(align(32))
#undef ALIGN32_END
#define ALIGN32_END
#endif

#define _PS256_CONST(Name, val)					\
	static const ALIGN32_BEG float _ps256_##Name[8] ALIGN32_END = {val,val,val,val,val,val,val,val}

#define _PS256_CONST_TYPE(Name, Type, val)		\
	static const ALIGN32_BEG Type _ps256_##Name[8] ALIGN32_END = {val,val,val,val,val,val,val,val}

#define _PI32_CONST256(Name, val)				\
	static const ALIGN32_BEG int _pi32_256_##Name[8] ALIGN32_END = {val,val,val,val,val,val,val,val}

typedef __m256 v8sf;
typedef __m256d v4sd;
typedef __m256i v8si;

typedef __m128i v4si;
typedef __m128 v4sf;

// default is big-endian which is different with x86
_PS256_CONST_TYPE(sign_mask, int, 0x80000000);
_PS256_CONST(0p5, 0.5f);
_PS256_CONST(1, 1.0f);
_PS256_CONST(2, 2.0f);

#endif /* __SIMD_CONST_H__ */
