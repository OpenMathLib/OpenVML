#ifndef _SIMD_POW_KERNEL_H_
#define _SIMD_POW_KERNEL_H_

#include "simd_const.h"
#include "simd_map.h"
#include "simd_exps_avx.h"
#include "simd_lns_avx.h"

_PI32_CONST256(pow_uint_1, 1);
_PI32_CONST256(pow_uint_0, 0);
_PS256_CONST_TYPE(pow_nan, int, 0xffffffff);
_PS256_CONST_TYPE(pow_fabs_mask, int, ~0x80000000);

static inline v8sf simd_pow8f(const v8sf aa, const v8sf bb)
{
    v8sf tem0, tem1, tem2, man;
    v8sf abs_a, abs_b, floor_b;
    v8sf out1, sign;
    v8sf out2, odd;

    const v8sf zero = simd_zeros;
    const v8sf mask = *(v8sf *) _ps256_sign_mask;
    const v8sf two = *(v8sf *) _ps256_2;
    const v8sf sone = *(v8sf *) _ps256_1;
    const v8sf nan = *(v8sf *) _ps256_pow_nan;

    const v8si uint_1 = *(v8si *) _pi32_256_pow_uint_1;
    const v8si uint_0 = *(v8si *) _pi32_256_pow_uint_0;
    v8si exp;
    v8sf cc;

    sign = simd_ands(mask, aa);
    // |a|
    abs_a = simd_ands(aa, *(v8sf *) _ps256_pow_fabs_mask);
    // |b|
    abs_b = simd_ands(bb, *(v8sf *) _ps256_pow_fabs_mask);

    /* using ln fuction */
    tem0 = simd_ln8f(abs_a);
    tem1 = simd_muls(tem0, bb);

    /* using exp fuction */
    cc = simd_exp8f(tem1);

    exp = simd_cvts_w(bb);

    man = simd_castw_s(simd_cmpeqw(simd_andw(exp, uint_1), uint_0));    //even or odd

    odd = simd_ors(sign, cc);
    out1 = simd_adds(simd_ands(man, cc), simd_andnots(man, odd));

    floor_b = simd_floors(bb);

    /* x<0 and y != N, then NAN */
    man = simd_andnots(simd_cmpeqs(bb, floor_b), simd_cmplts(aa, zero));
    out2 = simd_adds(simd_ands(man, nan), simd_andnots(man, out1));

    /* y = 0 then 1 */
    man = simd_cmpeqs(abs_b, zero);
    cc = simd_adds(simd_ands(man, sone), simd_andnots(man, out2));
    return cc;
}

#endif /* _SIMD_POW_KERNEL_H_ */
