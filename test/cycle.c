#include <stdlib.h>
#include <stdio.h>
#include "cycle.h"

#ifdef COMPILER_MSVC

#include <intrin.h>
#pragma intrinsic(__rdtsc)

#endif

/*
 * From the website
 * http://stackoverflow.com/questions/3247373/
 * how-to-measure-program-execution-time-in-arm-cortex-a8-processor
 * */

#ifdef __arm__

static int flag = 0;

static inline unsigned int get_cyclecount (void)
{
  unsigned int value;
  // Read CCNT Register
  asm volatile ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(value));  
  return value;
}

static inline void init_perfcounters (int32_t do_reset, int32_t enable_divider)
{
  // in general enable all counters (including cycle counter)
  int32_t value = 1;

  // peform reset:  
  if (do_reset)
  {
    value |= 2;     // reset all counters to zero.
    value |= 4;     // reset cycle counter to zero.
  } 

  if (enable_divider)
    value |= 8;     // enable "by 64" divider for CCNT.

  value |= 16;

  // program the performance-counter control-register:
  asm volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(value));  

  // enable all counters:  
  asm volatile ("MCR p15, 0, %0, c9, c12, 1\t\n" :: "r"(0x8000000f));  

  // clear overflows:
  asm volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
}

static inline unsigned int get_overhead()
{
	unsigned int cost = get_cyclecount();
	cost = get_cyclecount() - cost;
	return cost;
}
#endif

unsigned long long get_cycles(void)
{
#ifdef COMPILER_MSVC
  return (unsigned long long) __rdtsc();

#elif (defined(__arm__))
  if(flag == 0)
    init_perfcounters (1, 0);
  flag = 1;
  return (unsigned long long) get_cyclecount();

#elif (defined(__i386__) || defined(__x86_64__))
  unsigned long long low, high;
  asm volatile("rdtsc" : "=a"(low), "=d"(high));
  return (unsigned long long)(high << 32 | low);

#else 
  return 0; /* Failed */

#endif
}

