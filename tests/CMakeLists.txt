include(FetchContent)
FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.14.0)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(TemplateUnitTests)
set_target_properties(TemplateUnitTests PROPERTIES CXX_STANDARD 17)
target_link_libraries(TemplateUnitTests PRIVATE TemplateSources)

add_subdirectory(include)
add_subdirectory(src)

target_link_libraries(TemplateUnitTests PRIVATE gtest gtest_main gmock)

include(GoogleTest)
gtest_discover_tests(TemplateUnitTests)
