target_sources(Template PRIVATE main.cpp)

# tests implement their own main function - not adding main.cpp here
target_sources(TemplateSources INTERFACE
	Hello.cpp)
