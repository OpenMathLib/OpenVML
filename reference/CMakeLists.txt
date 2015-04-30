set(OpenVML_REF_SRC 
  vadd.c 
  vsub.c
  vpow.c
  vexp.c
  vtanh.c
  )

add_library(${OpenVML_LIBNAME}_ref SHARED ${OpenVML_REF_SRC})
if(NOT MSVC)
target_link_libraries(${OpenVML_LIBNAME}_ref m)
endif()

target_compile_definitions(${OpenVML_LIBNAME}_ref PUBLIC openvml_EXPORTS)