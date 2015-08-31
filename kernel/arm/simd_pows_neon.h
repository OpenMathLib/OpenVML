#ifndef _SIMD_POWS_KERNEL_H_
#define _SIMD_POWS_KERNEL_H_

#include "simd_const.h"
#include "simd_map.h"
#include "simd_exps_neon.h"
#include "simd_lns_neon.h"

_PI32_CONST128(pow_uint_1, 1);
_PI32_CONST128(pow_uint_0, 0);
_PS128_CONST_TYPE(pow_nan, int, 0xffffffff);

static inline v4sf simd_pow4f(const v4sf aa, const v4sf bb)
{
    v4sf tem0, tem1, tem2, man;
    v4sf abs_a, abs_b, floor_b;
    v4sf out1, sign;
    v4sf out2, odd;

    const v4sf zero = simd_zeros;
    const v4sf mask = *(v4sf *) _ps128_sign_mask;
    const v4sf two = *(v4sf *) _ps128_2;
    const v4sf sone = *(v4sf *) _ps128_1;
    const v4sf nan = *(v4sf *) _ps128_pow_nan;

    const v4si uint_1 = *(v4si *) _pi32_128_pow_uint_1;
    const v4si uint_0 = *(v4si *) _pi32_128_pow_uint_0;
    v4si exp;
    v4sf cc;

    {
        sign = simd_ands(mask, aa);
        abs_a = simd_fabs(aa);    //|a|
        abs_b = simd_fabs(bb);    //|b|

        /* using ln fuction */ 
        tem0 = simd_ln4f(abs_a);
        tem1 = simd_muls(tem0, bb);

        /* using exp fuction */ 
        cc = simd_exp4f(tem1);

        exp = simd_cvts_w(bb);

        man = simd_castu_s(simd_cmpeqw(simd_andw(exp, uint_1), uint_0));   //even or odd

        odd = simd_ors(sign, cc);
        out1 = simd_adds(simd_ands(man, cc), simd_andnots(man, odd));

        floor_b = simd_floors(bb);

        /* x<0 and y != N, then -NAN */
        man = simd_andnots(simd_cmpeqs(bb, floor_b), simd_cmplts(aa, zero));
        out2 = simd_adds(simd_ands(man, nan), simd_andnots(man, out1));

        /* y = 0 then 1 */
        man = simd_cmpeqs(abs_b, zero);
        cc = simd_adds(simd_ands(man, sone), simd_andnots(man, out2));
        return cc;
    }
}

#endif /* _SIMD_POWS_KERNEL_H_ */
