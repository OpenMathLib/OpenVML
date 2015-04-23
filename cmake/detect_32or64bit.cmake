#https://github.com/petroules/solar-cmake/blob/master/TargetArch.cmake

set(detect_32_64_code "
#include <stdint.h>
#if INTPTR_MAX == INT32_MAX
#error cmake_BINARY 32
#elif INTPTR_MAX == INT64_MAX
#error cmake_BINARY 64
#else
#error cmake_BINARY unknown
#endif
")

function(detect_32_64_bit output_var)
  file(WRITE "${CMAKE_BINARY_DIR}/32_64_bit.c" "${detect_32_64_code}")

  enable_language(C)

  try_run(
    run_result_unused
    compile_result_unused
    "${CMAKE_BINARY_DIR}"
    "${CMAKE_BINARY_DIR}/32_64_bit.c"
    COMPILE_OUTPUT_VARIABLE BINARY
    )

  string(REGEX MATCH "cmake_BINARY ([a-zA-Z0-9_]+)" BINARY "${BINARY}")

  string(REPLACE "cmake_BINARY " "" BINARY "${BINARY}")

  if (NOT BINARY)
    set(BINARY unknown)
  endif()
  set(${output_var} "${BINARY}" PARENT_SCOPE)
endfunction()