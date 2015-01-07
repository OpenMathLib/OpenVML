#ifndef _OPENVML_KERNEL_H_
#define _OPENVML_KERNEL_H_

#include "openvml_common.h"
#include "openvml_macros.h"

void OpenVML_FUNCNAME(sadd_k)(VMLLONG n, float * a, float * b, float * y);
void OpenVML_FUNCNAME(dadd_k)(VMLLONG n, double * a, double * b, double * y);

void OpenVML_FUNCNAME(ssub_k)(VMLLONG n, float * a, float * b, float * y);
void OpenVML_FUNCNAME(dsub_k)(VMLLONG n, double * a, double * b, double * y);

#endif