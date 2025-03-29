#
# Copyright(c) 2023 Andrey Borisovich. All rights reserved.
#
# SPDX-License-Identifier: Apache-2.0
#
cmake_minimum_required (VERSION 3.23)

project(MemoryManager DESCRIPTION "Training project for managing memory" LANGUAGES CXX)

add_executable(MemoryManagerDemo)

add_library(MemoryManagerSources INTERFACE)
set_target_properties(MemoryManagerDemo MemoryManagerSources PROPERTIES CXX_STANDARD 20)

# Configure MyAllocator
option(OVERRIDE_NEW_AND_DELETE "Enable to override new and delete operators to use MyAllocator" ON)

# Configure HeapMemoryTracker
set(MEMORY_POOL_SIZE_BYTES 100730) #1073741824

add_subdirectory(include)
add_subdirectory(src)

enable_testing()
add_subdirectory(test)

target_link_libraries(MemoryManagerDemo PRIVATE MemoryManagerSources)
