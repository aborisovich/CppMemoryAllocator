target_sources(MemoryAllocator PRIVATE main.cpp)

# tests implement their own main function - not adding main.cpp here
target_sources(MemoryAllocatorSources INTERFACE
	Hello.cpp)
