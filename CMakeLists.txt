cmake_minimum_required (VERSION 3.22)

project(CppMemoryAllocator DESCRIPTION "Custom memory allocator" LANGUAGES CXX)

add_executable(MemoryAllocator)

add_library(MemoryAllocatorSources INTERFACE)

target_compile_options(MemoryAllocatorSources INTERFACE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
set_target_properties(MemoryAllocatorSources PROPERTIES CXX_STANDARD 17)

add_subdirectory(include)
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

target_link_libraries(MemoryAllocator PRIVATE MemoryAllocatorSources)
