/**
 * @file MyAllocator.cpp
 * @copyright 2023 Andrey Borisovich. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * @author Andrey Borisovich
 */
#include <MemoryManager/MyAllocatorConfig.h>
#include <MemoryManager/MyAllocator.hpp>
#include <iostream>
#include <format>
#include <malloc.h>

#ifdef OVERRIDE_NEW_AND_DELETE

void* operator new(std::size_t size)
{
	return memory_manager::MyAllocator<void>().allocate(size);
}

void operator delete(void* memory, std::size_t size)
{
	memory_manager::MyAllocator<void>().deallocate(memory, size);
}

#endif
