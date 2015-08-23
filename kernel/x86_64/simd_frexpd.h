#ifndef _SIMD_FREXP_H_
#define _SIMD_FREXP_H_

#include "simd_const.h"
#include "simd_map.h"

static ALIGN32_BEG short frexp_7ff[16] ALIGN32_END = {
    0x0000, 0x0000, 0x0000, 0x7ff0, 0x0000, 0x0000, 0x0000, 0x7ff0,
    0x0000, 0x0000, 0x0000, 0x7ff0, 0x0000, 0x0000, 0x0000, 0x7ff0
};

static ALIGN32_BEG double frexp_2p0[4] ALIGN32_END = { 2.0, 2.0, 2.0, 2.0 };

static ALIGN32_BEG unsigned short frexp_800f[16] ALIGN32_END = {
    0xffff, 0xffff, 0xffff, 0x800f, 0xffff, 0xffff, 0xffff, 0x800f,
    0xffff, 0xffff, 0xffff, 0x800f, 0xffff, 0xffff, 0xffff, 0x800f
};

static ALIGN32_BEG unsigned short frexp_3fe0[16] ALIGN32_END = {
    0x0, 0x0, 0x0, 0x3fe0, 0x0, 0x0, 0x0, 0x3fe0,
    0x0, 0x0, 0x0, 0x3fe0, 0x0, 0x0, 0x0, 0x3fe0
};

static ALIGN32_BEG int ldexp_7ff[8] ALIGN32_END = {
    0x00000000, 0x7ff00000, 0x00000000, 0x7ff00000,
    0x00000000, 0x7ff00000, 0x00000000, 0x7ff00000
};

static ALIGN32_BEG unsigned short ldexp_inv_8fff0[16] ALIGN32_END = {
    0x0, 0x0, 0x0, 0xfff0, 0x0, 0x0, 0x0, 0xfff0,
    0x0, 0x0, 0x0, 0xfff0, 0x0, 0x0, 0x0, 0xfff0
};

static ALIGN32_BEG unsigned short ldexp_8fff0[16] ALIGN32_END = {
    0xffff, 0xffff, 0xffff, 0xf, 0xffff, 0xffff, 0xffff, 0xf,
    0xffff, 0xffff, 0xffff, 0xf, 0xffff, 0xffff, 0xffff, 0xf
};

static ALIGN32_BEG int frexp_ffff[8] ALIGN32_END = {
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff,
    0xffffffff, 0xffffffff, 0xffffffff, 0xffffffff
};

static ALIGN32_BEG int frexp_1022[8] ALIGN32_END = {
    1022, 1022, 1022, 1022,
    1022, 1022, 1022, 1022
};

static ALIGN32_BEG int frexp_zero[8] ALIGN32_END = { 0, 0, 0, 0, 0, 0, 0, 0 };

static inline v4sd simd_frexpd(const v4sd mx, v8si * pmw2)
{
    v4sd y;
    v8si temp0i;
    v8si temp1i;
    v8si temp2i;
    v4sd tempcmp;
    v4sd tempintcmp;

    tempcmp = simd_cmpeqd(mx, simd_zerod);
    temp1i = simd_orw(*(v8si *) frexp_3fe0, simd_andw(*(v8si *) & mx, *(v8si *) frexp_800f));
    y = simd_ord(simd_andd(tempcmp, simd_zerod), simd_andnotd(tempcmp, *(v4sd *) & temp1i));

    *pmw2 = simd_andw(*(v8si *) & mx, *(v8si *) ldexp_7ff);
    *pmw2 = simd_srliw(*pmw2, 20);
    *pmw2 = simd_subw(*pmw2, *(v8si *) frexp_1022);

    tempintcmp =
        simd_ord(simd_andd(tempcmp, *(v4sd *) frexp_ffff),
                 simd_andnotd(tempcmp, *(v4sd *) frexp_zero));
    *pmw2 =
        simd_orw(simd_andw(*(v8si *) & tempintcmp, *(v8si *) frexp_zero),
                 simd_andnotw(*(v8si *) & tempintcmp, *pmw2));

    return y;
}

static inline v4sd simd_ldexpd(const v4sd mx, const v8si mpw)
{
    v4sd y;
    v8si temp0i;
    v8si yi;
    v4sd temp0d;

    temp0d = simd_cmpeqd(mx, simd_zerod);
    temp0i = simd_andw(*(v8si *) & mx, *(v8si *) ldexp_inv_8fff0);
    temp0i = simd_srliw(temp0i, 20);
    temp0i = simd_addw(temp0i, mpw);
    temp0i = simd_slliw(temp0i, 20);

    yi = simd_orw(simd_andw(*(v8si *) & mx, *(v8si *) & ldexp_8fff0),
                  simd_andw(temp0i, *(v8si *) ldexp_inv_8fff0));

    y = simd_ord(simd_andd(temp0d, simd_zerod), simd_andnotd(temp0d, *(v4sd *) & yi));
    return y;
}

#endif /* _SIMD_FREXP_H_ */
