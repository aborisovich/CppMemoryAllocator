cmake_minimum_required (VERSION 3.22)

project(Template DESCRIPTION "Template C++ project" LANGUAGES CXX)

add_executable(Template)

add_library(TemplateSources INTERFACE)

target_compile_options(TemplateSources INTERFACE "$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
set_target_properties(TemplateSources PROPERTIES CXX_STANDARD 17)

add_subdirectory(include)
add_subdirectory(src)

enable_testing()
add_subdirectory(tests)

target_link_libraries(Template PRIVATE TemplateSources)
