#include "simd_const.h"
#include "simd_map.h"
#include "simd_frexpd.h"
#include "simd_polevld.h"
#include "simd_expd_avx.h"

static ALIGN32_BEG double tanhd_p[] ALIGN32_END = {
    -9.64399179425052238628E-1, -9.64399179425052238628E-1,
    -9.64399179425052238628E-1, -9.64399179425052238628E-1,
    -9.92877231001918586564E1, -9.92877231001918586564E1,
    -9.92877231001918586564E1, -9.92877231001918586564E1,
    -1.61468768441708447952E3, -1.61468768441708447952E3,
    -1.61468768441708447952E3, -1.61468768441708447952E3
};

static ALIGN32_BEG double tanhd_q[] ALIGN32_END = {
    1.12811678491632931402E2, 1.12811678491632931402E2,
    1.12811678491632931402E2, 1.12811678491632931402E2,
    2.23548839060100448583E3, 2.23548839060100448583E3,
    2.23548839060100448583E3, 2.23548839060100448583E3,
    4.84406305325125486048E3, 4.84406305325125486048E3,
    4.84406305325125486048E3, 4.84406305325125486048E3
};

static ALIGN32_BEG double tanhd_stf[] ALIGN32_END = {0.625,0.625,0.625,0.625};
static ALIGN32_BEG double tanhd_0p5[] ALIGN32_END = {0.5,0.5,0.5,0.5};
static ALIGN32_BEG double tanhd_minus_1p0[] ALIGN32_END = {-1.0,-1.0,-1.0,-1.0};
static ALIGN32_BEG double tanhd_1p0[] ALIGN32_END = {1.0,1.0, 1.0,1.0};
static ALIGN32_BEG double tanhd_2p0[] ALIGN32_END = {2.0,2.0,2.0,2.0};
static ALIGN32_BEG double tanhd_max_log[] ALIGN32_END = {
	7.08396418532264106224E2,7.08396418532264106224E2,     /* log 2**1022 */
	7.08396418532264106224E2,7.08396418532264106224E2
};

static inline v4sd simd_tanh4d(const v4sd s128d)
{
    v4sd temp0d;
    v4sd temp1d;
    v4sd temp2d;
    v4sd temp3d;
    v4sd tempz;
    v4sd temps;
    v4sd tempx_0;
    v4sd temp1dz;
    v4sd temp2dz;
    v4sd zero = simd_zerod;

    /*
     * if (x == 0.0)
     * return(x);
     */
    temp0d = simd_cmpeqd(s128d, zero);

    /*
     * z = fabs(x);
     * if (z > 0.5 * MAXLOG)
     * {
     * if (x > 0)
     * return(1.0);
     * else
     * return(-1.0);
     * }
     */
    temp1d = simd_cmpltd(s128d, zero);
    tempz = simd_ord(simd_andd(temp1d, simd_subd(zero, s128d)), simd_andnotd(temp1d, s128d));
    temp1d = simd_cmpltd(simd_muld(*(v4sd *) tanhd_0p5, *(v4sd *) tanhd_max_log), tempz);

    tempx_0 = simd_cmpltd(zero, s128d);
    temp1dz = simd_ord(simd_andd(tempx_0, *(v4sd *) tanhd_minus_1p0),
                 simd_andnotd(tempx_0, *(v4sd *) tanhd_1p0));

    /*
     * if (z >= 0.625) {
     * s = exp(2.0 * z);
     * z = 1.0 - 2.0 / (s + 1.0);
     * if (x < 0)
     * z = -z;
     * }
     */

    temp2d = simd_cmpled(*(v4sd *) tanhd_stf, tempz);
    temp3d = simd_muld(*(v4sd *) tanhd_2p0, tempz);
    temps = simd_exp4d(temp3d);
    temp2dz = simd_subd(*(v4sd *) tanhd_1p0,
                  simd_divd(*(v4sd *) tanhd_2p0, simd_addd(temps, *(v4sd *) tanhd_1p0)));

    temp2dz = simd_ord(simd_andd(tempx_0, temp2dz),
                 simd_andnotd(tempx_0, simd_subd(zero, temp2dz)));
    /*
     * else {
     * if (x == 0.0)
     * return(x);
     * s = x * x;
     * z = polevl(s, tanhd_p, 2)/p1evl(s, tanhd_q, 3);
     * z = x * s * z;
     * z = x + z;
     * }
     * return(z);
     */
    temps = simd_muld(s128d, s128d);
    tempz = simd_divd(simd_polevld(temps, (v4sd *) tanhd_p, 2),
                  simd_p1evld(temps, (v4sd *) tanhd_q, 3));

    tempz = simd_muld(simd_muld(s128d, temps), tempz);
    tempz = simd_addd(s128d, tempz);
    tempz = simd_ord(simd_andd(temp2d, temp2dz), simd_andnotd(temp2d, tempz));
    tempz = simd_ord(simd_andd(temp1d, temp1dz), simd_andnotd(temp1d, tempz));
    tempz = simd_ord(simd_andd(temp0d, zero), simd_andnotd(temp0d, tempz));

    return tempz;
}
