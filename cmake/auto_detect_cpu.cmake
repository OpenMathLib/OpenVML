set (OpenVML_ARCH "generic")
set (OpenVML_CPU_CORENAME "generic")

try_run(arch_detect_result arch_detect_compile_result
  ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/cmake/arch_detect.c
  RUN_OUTPUT_VARIABLE arch_detect_output
  )

if(arch_detect_compile_result)
if(arch_detect_result EQUAL 0)
set (OpenVML_ARCH ${arch_detect_output})
endif()
endif()

#For x86_64
if(OpenVML_ARCH STREQUAL "x86_64")
try_run(cpu_detect_result cpu_detect_compile_result
  ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/cmake/cpuid_x86.c
  RUN_OUTPUT_VARIABLE cpu_detect_output
  )
endif()

if(cpu_detect_compile_result)
if(cpu_detect_result EQUAL 0)
set (OpenVML_CPU_CORENAME ${cpu_detect_output})
endif()
endif()


message(STATUS "Detect Arch:" ${OpenVML_ARCH} "\tCPU:" ${OpenVML_CPU_CORENAME})