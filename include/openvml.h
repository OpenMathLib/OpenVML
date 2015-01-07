#ifndef _OPENVML_H_
#define _OPENVML_H_

#include "openvml_export.h"
#include "openvml_common.h"

#ifdef __cplusplus
extern "C" {
#endif

OPENVML_EXPORT void OpenVML_FUNCNAME(vsAdd)(VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdAdd)(VML_INT n, const double * a, const double * b, double * y);

OPENVML_EXPORT void OpenVML_FUNCNAME(vsSub)(VML_INT n, const float * a, const float * b, float * y);
OPENVML_EXPORT void OpenVML_FUNCNAME(vdSub)(VML_INT n, const double * a, const double * b, double * y);

#ifdef __cplusplus
}
#endif
#endif