#ifndef	__SIMD_MAP_H
#define	__SIMD_MAP_H

#include "simd_const.h"

#define simd_zeros			vmovq_n_f32(0.0f) 	

#define simd_adds			vaddq_f32
#define simd_addw			vaddq_s32	
#define simd_andw			vandq_s32
#define simd_notw			vmvnq_s32
#define simd_subs			vsubq_f32
#define simd_subw			vsubq_s32
#define simd_muls			vmulq_f32
#define simd_rcps(b)			vrecpeq_f32(b)

//#define simd_divs(a,b)			vmulq_f32(a,vrecpeq_f32(b)) 	

static inline v4sf simd_divs(v4sf a, v4sf b)
{
  v4sf i_d = simd_rcps(b);
  i_d = simd_subs(simd_adds(i_d, i_d),simd_muls(b, simd_muls(i_d, i_d)));
  return simd_muls(a, i_d);
}


#define simd_sqrts			vsqrtq_f32
#define simd_casts_w			vreinterpretq_s32_f32 // cast float to int
#define simd_castw_s			vreinterpretq_f32_s32 // cast int to float
#define simd_castu_s			vreinterpretq_f32_u32 // cast uint to float

#define simd_ands(a,b)			vreinterpretq_f32_s32(vandq_s32(vreinterpretq_s32_f32(a),vreinterpretq_s32_f32(b)))
#define simd_andnots(b,a)		vreinterpretq_f32_s32(vbicq_s32(vreinterpretq_s32_f32(a),vreinterpretq_s32_f32(b)))
#define simd_xors(a,b)			vreinterpretq_f32_s32(veorq_s32(vreinterpretq_s32_f32(a),vreinterpretq_s32_f32(b)))
#define simd_ors(a,b)			vreinterpretq_f32_s32(vorrq_s32(vreinterpretq_s32_f32(a),vreinterpretq_s32_f32(b)))
#define simd_andnotw(a,b)		vbicq_s32(b,a)

//#define simd_floors			vrndqm_f32	// towards -Inf 

#define simd_floors(a)			simd_cvtw_s(simd_cvts_w(a)); 

// uint32x4_t vcltq_f32 (float32x4_t __a, float32x4_t __b) 
#define simd_cmplts(a,b)		vreinterpretq_f32_u32(vcltq_f32(a,b)) 

// uint32x4_t vcleq_f32 (float32x4_t __a, float32x4_t __b)
#define simd_cmples(a,b)		vreinterpretq_f32_u32(vcleq_f32(a,b))
#define simd_cmpges(a,b)		vreinterpretq_f32_u32(vcgeq_f32(a,b))

#define simd_cmpeqw(a,b)		vceqq_s32(a,b) 
#define simd_cmpeqs(a,b)		vreinterpretq_f32_u32(vceqq_f32(a,b)) 
#define simd_sllw(a,b)			vshlq_n_s32(a,b) 
#define simd_srlw(a,b)			vshrq_n_s32(a,b)

#define simd_negs			vnegq_f32 // ri = -ai
#define simd_fabs			vabsq_f32 // |va|

// if a is true and select c, else b
static inline v4sf simd_selects(v4sf a, v4sf b, v4sf c)
{
  v4si conn = simd_casts_w(a);
  v4si cona = simd_andw(conn, simd_casts_w(c));
  v4si conb = simd_andnotw(conn, simd_casts_w(b));
  v4si con = simd_addw(cona, conb);
  return simd_castw_s(con); 
}

#define simd_mas(a,b,c)			vaddq_f32(vmulq_f32(a,b),c) // vfmaq_f32(c,a,b) // vmlaq_f32(c,a,b) // va*vb+vc
#define simd_nmas(a,b,c)		vsubq_f32(c,vmulq_f32(a,b)) // vfmsq_f32(c,a,b) // vmlsq_f32(c,a,b) // vc-va*vb

#define simd_cvts_w			vcvtq_s32_f32 // convert float to int
#define simd_cvtw_s			vcvtq_f32_s32 // convert int to float
#define simd_cvtu_s			vcvtq_f32_u32 // convert uint to float

#define simd_maxw			vmaxq_s32
#define simd_minw			vminq_s32

#define simd_maxs			vmaxq_f32
#define simd_mins			vminq_f32

#endif /*__SIMD_MAP_H */
