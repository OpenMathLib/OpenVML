#ifndef _SIMD_TANH_KERNEL_H_
#define _SIMD_TANH_KERNEL_H_

#include "simd_const.h"
#include "simd_map.h"
#include "simd_exps_avx.h"

_PS256_CONST(tanh_0p625, 0.625f);
_PS256_CONST(tanh_p0, -5.70498872745E-3f);
_PS256_CONST(tanh_p1, 2.06390887954E-2f);
_PS256_CONST(tanh_p2, -5.37397155531E-2f);
_PS256_CONST(tanh_p3, 1.33314422036E-1f);
_PS256_CONST(tanh_p4, -3.33332819422E-1f);
_PS256_CONST(tanh_half_max, 44.014845935754205f);
_PS256_CONST_TYPE(tanh_fabs_mask, int, ~0x80000000);

static inline v8sf simd_tanh8f(const v8sf a)
{
    v8sf x, y, z, b;
    v8sf tem0, tem1, tem2, tem3;
    const v8sf one = *(v8sf *) _ps256_1;
    const v8sf zero = simd_zeros;
    const v8sf mask = *(v8sf *) _ps256_sign_mask;
    v8sf sign_bit;

    /* extract the sign bit (upper one) */
    sign_bit = simd_ands(mask, a);

    /* take the absolute value */
	x = simd_ands(a, *(v8sf *) _ps256_tanh_fabs_mask);
	//return x;	
    /*
     * if (x >= 0.625)
     * {
     * x = expf(x+x);
     * z =  1.0  - 2.0/(x + 1.0);
     * if (xx < 0)
     * z = -z;
     * }
     */
    tem1 = simd_cmplts(x, *(v8sf *) _ps256_tanh_0p625);
    tem2 = simd_adds(x, x);

    // call exponential function
    z = simd_exp8f(tem2);

    tem2 = simd_subs(one, simd_divs(*(v8sf *) _ps256_2, simd_adds(one, z)));
    tem0 = simd_ors(sign_bit, tem2);
    tem2 = tem0;
	
    /*
     * z = x * x;
     * z =
     * ((((-5.70498872745E-3 * z
     * + 2.06390887954E-2) * z
     * - 5.37397155531E-2) * z
     * + 1.33314422036E-1) * z
     * - 3.33332819422E-1) * z * xx
     * + xx;
     */
    
    tem0 = simd_muls(x, x);
    y = simd_mas(*(v8sf *) _ps256_tanh_p0, tem0, *(v8sf *) _ps256_tanh_p1);
    tem3 = simd_mas(y, tem0, *(v8sf *) _ps256_tanh_p2);
    y = simd_mas(tem3, tem0, *(v8sf *) _ps256_tanh_p3);
    tem3 = simd_mas(y, tem0, *(v8sf *) _ps256_tanh_p4);
    y = simd_muls(tem3, tem0);
    tem3 = simd_mas(y, a, a);

    z = simd_selects(tem1, tem2, tem3);

    /*
     * if (x > 0.5 * MAXLOGF)
     * {
     * if (xx > 0)
     * return(1.0);
     * else
     * return(-1.0);
     * }
     */
    
	//deal with the boundary
    tem0 = simd_cmples(x, *(v8sf *) _ps256_tanh_half_max);
    tem2 = simd_xors(sign_bit, one);
    tem1 = simd_selects(tem0, tem2, z);
    b = tem1;
    return b;
}
#endif /* SIMD_TANH_KERNEL_H_ */
