include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.14.0)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(MemoryAllocatorUnitTests)
set_target_properties(MemoryAllocatorUnitTests PROPERTIES CXX_STANDARD 17)
target_link_libraries(MemoryAllocatorUnitTests PRIVATE MemoryAllocatorSources)

add_subdirectory(include)
add_subdirectory(src)

target_link_libraries(MemoryAllocatorUnitTests PRIVATE gtest gtest_main gmock)

include(GoogleTest)
gtest_discover_tests(MemoryAllocatorUnitTests)
