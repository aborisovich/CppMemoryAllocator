#
# Copyright(c) 2023 Andrey Borisovich. All rights reserved.
#
# SPDX-License-Identifier: Apache-2.0
#
target_sources(MemoryManagerSources INTERFACE
	MyAllocator.cpp
	HeapMemoryTracker.cpp
	PoolOutOfMemoryException.cpp)

target_sources(MemoryManagerDemo PRIVATE main.cpp)
