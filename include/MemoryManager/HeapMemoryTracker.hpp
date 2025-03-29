/**
 * @file SystemMemoryTracker.hpp
 * @copyright 2023 Andrey Borisovich. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * @author Andrey Borisovich
 */
#pragma once
#include <cstddef>
#include <MemoryManager/HeapMemoryTrackerConfig.h>


namespace memory_manager
{


/**
 * @brief This class exposes no public interfaces or members.
 * It's purpose is to be derived classes matching criteria of C++ Allocator.
 */
class HeapMemoryTracker
{
public:
	/**
	 * @brief Get the available memory size.
	 *
	 * @return std::size_t Amount of non-allocated memory in bytes.
	 */
	static std::size_t get_available_memory();

protected:
	/**
	 * @brief Fulfills criteria of the C++ Allocator class requirements - default constructible.
	 */
	HeapMemoryTracker() = default;
	explicit HeapMemoryTracker(const HeapMemoryTracker&) noexcept {}
	explicit HeapMemoryTracker(HeapMemoryTracker&&) noexcept {}
	HeapMemoryTracker& operator=(const HeapMemoryTracker&) = delete;
	HeapMemoryTracker& operator=(HeapMemoryTracker&&) = delete;
	virtual ~HeapMemoryTracker() = default;

	/**
	 * @brief Reserves desired amount of memory in the memory pool of the MEMORY_POOL_SIZE_BYTES.
	 * If There is not enough memory, OutOfMemoryException is thrown.
	 * @param size Size of the memory to be reserved.
	 */
	static void reserve_memory(std::size_t size);

	/**
	 * @brief Frees desired amount of memory from the memory pool of the MEMORY_POOL_SIZE_BYTES.
	 * @param size Size of the memory to be freed.
	 */
	static void release_memory(std::size_t size);

private:
	/**
	 * @brief Signed representation of the size_t that holds currently available heap memory.
	 * Variable is static to match stateless implementation of the C++ Allocator.
	 */
	static std::size_t available_memory;
};

}
