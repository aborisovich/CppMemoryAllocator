/**
 * @file SystemMemoryTracker.cpp
 * @copyright 2023 Andrey Borisovich. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * @author Andrey Borisovich
 */
#include <MemoryManager/HeapMemoryTracker.hpp>
#include <MemoryManager/PoolOutOfMemoryException.hpp>
#include <iostream>

namespace memory_manager
{

constinit size_t HeapMemoryTracker::available_memory = MEMORY_POOL_SIZE_BYTES;

void HeapMemoryTracker::reserve_memory(std::size_t size)
{
	if(available_memory < size)
		throw PoolOutOfMemoryException(size, available_memory);
	available_memory -= size;
}

void HeapMemoryTracker::release_memory(std::size_t size)
{
	available_memory += size;
}

std::size_t HeapMemoryTracker::get_available_memory()
{
	return available_memory;
}

}
