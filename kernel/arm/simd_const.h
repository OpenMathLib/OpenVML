#ifndef __SIMD_CONST_H__
#define __SIMD_CONST_H__

#include <stdlib.h>
#include <stdio.h>
#include <arm_neon.h>

#ifndef ALIGN16_BEG
#define ALIGN16_BEG
#endif

#ifndef ALIGN16_END
#define ALIGN16_END __attribute__((aligned(16)))
#endif

#define _PS128_CONST(Name, val)					\
	static const ALIGN16_BEG float _ps128_##Name[4] ALIGN16_END = {val,val,val,val}

#define _PS128_CONST_TYPE(Name, Type, val)		\
	static const ALIGN16_BEG Type _ps128_##Name[4] ALIGN16_END = {val,val,val,val}

#define _PI32_CONST128(Name, val)				\
	static const ALIGN16_BEG int _pi32_128_##Name[4] ALIGN16_END = {val,val,val,val}

typedef float32x4_t v4sf;
typedef int32x4_t v4si;

// default is big-endian which is different with x86
_PS128_CONST_TYPE(sign_mask, int, 0x80000000);
_PS128_CONST(0p5, 0.5f);
_PS128_CONST(1, 1.0f);
_PS128_CONST(2, 2.0f);

#endif /* __SIMD_CONST_H__ */
