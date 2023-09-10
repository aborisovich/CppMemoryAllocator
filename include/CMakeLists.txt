target_include_directories(TemplateSources INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Include headers in target_sources to define inclusions between targets
target_sources(TemplateSources INTERFACE
	template/Hello.hpp)
