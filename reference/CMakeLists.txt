set(OpenVML_REF_SRC 
  vadd.c 
  vsub.c
  vsqr.c
  vpow.c
  vpowx.c
  vpow2o3.c
  vpow3o2.c
  vexp.c
  vexpm1.c
  vtanh.c
  vlog10.c
  vln.c
  vlog1p.c
  vfloor.c
  vfmax.c
  vfmin.c
  vmean.c
  vvariance.c
  FIRSRGetSize.c
  FIRSRInit_32f.c
  FIRSR_32f.c
  vsin.c
  vcos.c
  vsincos.c
  vtan.c
  vasin.c
  vacos.c
  vatan.c
  vatan2.c
  )

add_library(${OpenVML_LIBNAME}_ref SHARED ${OpenVML_REF_SRC})
if(NOT MSVC)
target_link_libraries(${OpenVML_LIBNAME}_ref m)
endif()

target_compile_definitions(${OpenVML_LIBNAME}_ref PUBLIC openvml_EXPORTS)
