#
# Copyright(c) 2023 Andrey Borisovich. All rights reserved.
#
# SPDX-License-Identifier: Apache-2.0
#
if(NOT OVERRIDE_NEW_AND_DELETE)
	set(OVERRIDE_NEW_AND_DELETE "")
endif()
configure_file(MemoryManager/MyAllocatorConfig.h.in MemoryManager/MyAllocatorConfig.h @ONLY)
configure_file(MemoryManager/HeapMemoryTrackerConfig.h.in MemoryManager/HeapMemoryTrackerConfig.h @ONLY)

target_include_directories(MemoryManagerSources INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_include_directories(MemoryManagerSources INTERFACE ${CMAKE_CURRENT_BINARY_DIR})

