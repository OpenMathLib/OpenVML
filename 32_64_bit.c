
#include <stdint.h>
#if INTPTR_MAX == INT32_MAX
#error cmake_BINARY 32
#elif INTPTR_MAX == INT64_MAX
#error cmake_BINARY 64
#else
#error cmake_BINARY unknown
#endif
