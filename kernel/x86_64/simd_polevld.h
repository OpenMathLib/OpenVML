#ifndef _SIMD_POLEVLD_H_
#define _SIMD_POLEVLD_H_

#include "simd_map.h"
#include "simd_const.h"

static inline v4sd simd_polevld(v4sd x, v4sd * coef, int N)
{
    int i;
    v4sd s256d;
    v4sd *p = coef;
    s256d = *p++;
    i = N;
    do {
        s256d = simd_addd(simd_muld(s256d, x), *p);
        p++;
    } while (--i);

    return s256d;
}

static inline v4sd simd_p1evld(v4sd x, v4sd * coef, int N)
{
    int i;
    v4sd s256d;
    v4sd *p;

    p = coef;
    s256d = simd_addd(x, *p);
    p++;
    i = N - 1;

    do {
        s256d = simd_addd(simd_muld(s256d, x), *p);
        p++;
    } while (--i);
    return s256d;
}

#endif /* _SIMD_POLEVLD_H_ */
