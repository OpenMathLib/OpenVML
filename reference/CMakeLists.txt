set(OpenVML_REF_SRC 
  vadd.c 
  vsub.c
  )

add_library(${OpenVML_LIBNAME}_ref SHARED ${OpenVML_REF_SRC})
target_link_libraries(${OpenVML_LIBNAME}_ref m)

