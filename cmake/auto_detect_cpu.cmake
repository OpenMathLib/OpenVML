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

if(MSVC)
  set(OpenVML_CPU_DETECT_FLAGS
    ${OpenVML_CPU_DETECT_FLAGS} -DCOMPILER_MSVC)
endif()

try_run(cpu_detect_result cpu_detect_compile_result
  ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/cmake/cpuid_x86.c
  COMPILE_DEFINITIONS ${OpenVML_CPU_DETECT_FLAGS}
  RUN_OUTPUT_VARIABLE cpu_detect_output
  COMPILE_OUTPUT_VARIABLE cpu_detect_compile_output
  )
#if(MSVC)
#  set(cpu_detect_output "generic")
#endif()
endif()


#For ARM 32-bit
if(OpenVML_ARCH STREQUAL "arm")
try_run(cpu_detect_result cpu_detect_compile_result
  ${PROJECT_BINARY_DIR} ${PROJECT_SOURCE_DIR}/cmake/cpuid_arm.c
  COMPILE_DEFINITIONS ${OpenVML_CPU_DETECT_FLAGS}
  RUN_OUTPUT_VARIABLE cpu_detect_output
  COMPILE_OUTPUT_VARIABLE cpu_detect_compile_output
  )
endif()

if(cpu_detect_compile_result)
if(cpu_detect_result EQUAL 0)
set (OpenVML_CPU_CORENAME ${cpu_detect_output})
else()
message("${cpu_detect_output}")
endif()
else()
#message("detect compile error")
#message("${cpu_detect_compile_output}")
endif()


message(STATUS "Detect Arch:" ${OpenVML_ARCH} "\tCPU:" ${OpenVML_CPU_CORENAME})