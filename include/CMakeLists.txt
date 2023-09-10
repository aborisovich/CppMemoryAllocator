target_include_directories(MemoryAllocatorSources INTERFACE ${CMAKE_CURRENT_LIST_DIR})

# Include headers in target_sources to define inclusions between targets
target_sources(MemoryAllocatorSources INTERFACE
	template/Hello.hpp)
