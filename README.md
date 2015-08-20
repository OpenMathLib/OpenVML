# OpenVML

[![Join the chat at https://gitter.im/xianyi/OpenVML](https://badges.gitter.im/Join%20Chat.svg)](https://gitter.im/xianyi/OpenVML?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

OpenVML is an open soruce vector math library.

## Support Processors and OS

* Generic platform
  * C and unoptimized codes

* OS
  * Linux
  * Mac OSX
  * Windows (Visual Studio or MinGW)

* x86_64
  * Intel Sandy Bridge
  * Intel Haswell

* ARM
  * ARMv7 (Cortex-A9, Cortex-A15)

## Compile

You need (CMake)[www.cmake.org] on your platform.

* Linux or Mac OSX:

```
mkdir /your/build
cd /your/build
cmake /path/to/OpenVML
make
make install
```

* Visual Studio
 * Use cmake or cmake-gui to generate Visual Studio solution files.
 * Use Visual Studio to open the solution and build.

## Test

 * Check the result and Performance

   Run `/your/build/test/run_vml_test`.
   For exmaple,
   ```
   ./run_vml_test                          # Run all test
   ./run_vml_test  -r check_result_s       # Only run single precision functions.
   ./run_vml_test  -r check_result_s add   # Only run single precision add function (vsAdd).
   ./run_vml_test  -n 1 10 2               # The input sizes are from 1 to 10, step 2.
   ```

 * Misc test

   Run `/your/build/test/misc_test`.

## Status

Ongoing work
