/**
 * @file PoolOutOfMemoryException.hpp
 * @copyright 2025 Andrey Borisovich. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * @author Andrey Borisovich
 */

#pragma once

#include <memory>

namespace memory_manager
{

/**
 * @brief Thrown  when there is not enough memory in the
 * available memory pool to allocate the object.
 * Build error message using only stack memory.
 */
class PoolOutOfMemoryException final : public std::bad_alloc
{
public:
	explicit PoolOutOfMemoryException(std::size_t requested_memory_size, std::size_t available_memory_size);

	/**
	 * @brief Message of the exception informing that there is not enough memory.
	 * Does not allocate any pool memory itself.
	*/
	const char* what() const noexcept override;

private:
	/**
	 * @brief Requested memory allocation size that caused the exception.
	 *
	 */
	std::size_t requested_memory_size;

	/**
	 * @brief Available memory size in the pool at the time of exception.
	 *
	 */
	std::size_t available_memory_size;

	/**
	 * @brief Message parts to avoid dynamic memory allocation in what() function.
	 *
	 */
	const char* message_header = "Not enough available memory pool of the allocator to allocate the object.";
	const char* message_requested_size = "\nRequested memory size: ";
	const char* message_available_size = "\nAvailable memory size: ";

	/**
	 * @brief A buffer containing complete error message.
	 * Combined message text has 122 characters, while std::size_t may be up to
	 * 18,446,744,073,709,551,615 on 64 bit architectures - that is up to 20 characters (two times).
	 */
	char error_message[150] = {0};
};

}
