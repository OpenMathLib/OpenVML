#ifndef _OPENVML_CONST_H_
#define _OPENVML_CONST_H_

#include <arm_neon.h>
#include <stdlib.h>
#include <stdio.h>

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

static ALIGN16_BEG int Z[4] ALIGN16_END = {0x0,0x0,0x0,0x0};

static ALIGN16_BEG int F[4] ALIGN16_END = {0xffffffff,0xffffffff,0xffffffff,0xffffffff};

static ALIGN16_BEG float soi_mask[4] ALIGN16_END =
    {12582912.0f,12582912.0f,12582912.0f,12582912.0f};

_PS128_CONST_TYPE(sign_mask, int, 0x80000000);
_PS128_CONST(0p5, 0.5f);
_PS128_CONST(1, 1.0f);
_PS128_CONST(2, 2.0f);

_PS128_CONST_TYPE(inv_nan, int, 0Xffffffff);
_PS128_CONST_TYPE(nan, int, 0X7fffffff);
_PS128_CONST_TYPE(pnan, int, 0X7fffffff);

#endif /* _OPENVML_CONST_H_ */
