set(OpenVML_REF_SRC 
  vadd.c 
  vsub.c
  vpow.c
  vpowx.c
  vpow2o3.c
  vpow3o2.c
  vexp.c
  vtanh.c
  vlog10.c
  vln.c
  vlog1p.c
  vfloor.c
  )

add_library(${OpenVML_LIBNAME}_ref SHARED ${OpenVML_REF_SRC})
if(NOT MSVC)
target_link_libraries(${OpenVML_LIBNAME}_ref m)
endif()

target_compile_definitions(${OpenVML_LIBNAME}_ref PUBLIC openvml_EXPORTS)