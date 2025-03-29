# Memory Manager Training

Memory Mananger training shows variations on how memory can be controlled in applications.
It may be used to control available memory on server application to provide horizontal scalability
and know when to deploy another server instance when a running one runs out of memory.
It may be used to avoid memory fragmentation or define memory alignment rules that may favor
memory conservation over speed of access.

## How to build

Memory Mananger uses [CMake presets](https://cmake.org/cmake/help/latest/manual/cmake-presets.7.html) system to build and execute unit tests.  
Minimal requirements are:
- [CMake](https://cmake.org/download/) 3.23.0 or newer
- C++20
