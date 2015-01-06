#ifndef _OPENVML_H_
#define _OPENVML_H_

#include "openvml_export.h"
#include "openvml_common.h"

#ifdef __cplusplus
extern "C" {
#endif

OPENVML_EXPORT void vsAdd(VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void vdAdd(VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void vsSub(VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void vdSub(VML_INT n, const double * a, const double * b, double * y);

#ifdef __cplusplus
}
#endif
#endif