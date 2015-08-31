#ifndef _SIMD_LNS_KERNEL_H_
#define _SIMD_LNS_KERNEL_H_

#include "simd_map.h"
#include "simd_const.h"

_PS128_CONST(SQRTHF, 0.707106781186547524);
_PS128_CONST(log_p0, 7.0376836292E-2);
_PS128_CONST(log_p1, -1.1514610310E-1);
_PS128_CONST(log_p2, 1.1676998740E-1);
_PS128_CONST(log_p3, -1.2420140846E-1);
_PS128_CONST(log_p4, +1.4249322787E-1);
_PS128_CONST(log_p5, -1.6668057665E-1);
_PS128_CONST(log_p6, +2.0000714765E-1);
_PS128_CONST(log_p7, -2.4999993993E-1);
_PS128_CONST(log_p8, +3.3333331174E-1);
_PS128_CONST(log_q1, -2.12194440e-4);
_PS128_CONST(log_q2, 0.693359375);
_PI32_CONST128(log_0x7f, 0x7f);

/* the smallest non denormalized float number */
_PS128_CONST_TYPE(min_norm_pos, int, 0x00800000);
_PS128_CONST_TYPE(mant_mask, int, 0x7f800000);
_PS128_CONST_TYPE(inv_mant_mask, int, ~0x7f800000);
_PS128_CONST_TYPE(lns_inv_inf, int, 0xff800000);
_PS128_CONST_TYPE(lns_nan, int, 0x7fffffff);


static inline v4sf simd_ln4f(const v4sf a)
{
    v4si imm0;
    v4sf e, ee, y, z;
    v4sf one = *(v4sf *) _ps128_1;
    v4sf mask;
    v4sf tmp;
	v4sf x = a;
    v4sf invalid_mask = simd_cmplts(x, simd_zeros);

    /* cut off denormalized stuff */
    x = simd_maxs(x, *(v4sf *) _ps128_min_norm_pos);
    imm0 = simd_srlw(simd_casts_w(x), 23);

    /* keep only the fractional part */
    x = simd_ands(x, *(v4sf *) _ps128_inv_mant_mask);
    x = simd_ors(x, *(v4sf *) _ps128_0p5);

    imm0 = simd_subw(imm0, *(v4si *) _pi32_128_log_0x7f);
    e = simd_cvtw_s(imm0);

    /* part2:
     * if (x < SQRTHF) {
     *    e -= 1;
     *    x = x + x - 1.0;
     * } else {
     *  x = x - 1.0;
     * }
     */
	
    mask = simd_cmplts(x, *(v4sf *) _ps128_SQRTHF);
    e = simd_adds(e, one);
		
    tmp = simd_ands(x, mask);
    x = simd_subs(x, one);
    e = simd_subs(e, simd_ands(one, mask));
    x = simd_adds(x, tmp);

    z = simd_muls(x, x);

    y = *(v4sf *) _ps128_log_p0;
    tmp = simd_mas(y, x, *(v4sf *) _ps128_log_p1);
    y = simd_mas(tmp, x, *(v4sf *) _ps128_log_p2);
    tmp = simd_mas(y, x, *(v4sf *) _ps128_log_p3);
    y = simd_mas(tmp, x, *(v4sf *) _ps128_log_p4);
    tmp = simd_mas(y, x, *(v4sf *) _ps128_log_p5);
    y = simd_mas(tmp, x, *(v4sf *) _ps128_log_p6);
    tmp = simd_mas(y, x, *(v4sf *) _ps128_log_p7);
    y = simd_mas(tmp, x, *(v4sf *) _ps128_log_p8);
    tmp = simd_muls(y, x);
    y = simd_muls(tmp, z);

    y = simd_mas(e, *(v4sf *) _ps128_log_q1, y);
    y = simd_nmas(z, *(v4sf *) _ps128_0p5, y);

    x = simd_adds(x, y);
    x = simd_mas(e, *(v4sf *) _ps128_log_q2, x);

    // zero arg will be -INF
    mask = simd_cmpeqs(a, simd_zeros);
    x = simd_adds(simd_ands(mask,*(v4sf *) _ps128_lns_inv_inf), simd_andnots(mask, x));

    // negative arg will be NAN
    x = simd_adds(simd_ands(invalid_mask,*(v4sf *) _ps128_lns_nan), simd_andnots(invalid_mask, x));

    return x;
}

#endif /* _SIMD_LNS_KERNEL_ */
