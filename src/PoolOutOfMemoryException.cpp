/**
 * @file PoolOutOfMemoryException.cpp
 * @copyright 2025 Andrey Borisovich. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * @author Andrey Borisovich
 */
#include <MemoryManager/PoolOutOfMemoryException.hpp>
#include <cstring>

namespace memory_manager
{

PoolOutOfMemoryException::PoolOutOfMemoryException(std::size_t requested_memory_size, std::size_t available_memory_size)
	: requested_memory_size(requested_memory_size), available_memory_size(available_memory_size)
{ }

const char* PoolOutOfMemoryException::what() const noexcept
{
	char bytes_number_buffer[21];
	std::snprintf(bytes_number_buffer, sizeof(bytes_number_buffer), "%zu", requested_memory_size);

	std::strncpy(const_cast<char*>(error_message), message_header, sizeof(message_header));
	std::strncpy(const_cast<char*>(error_message), message_requested_size, sizeof(message_requested_size));
	std::strncpy(const_cast<char*>(error_message), bytes_number_buffer, sizeof(bytes_number_buffer));

	std::snprintf(bytes_number_buffer, sizeof(bytes_number_buffer), "%zu", available_memory_size);

	std::strncpy(const_cast<char*>(error_message), message_available_size, sizeof(message_available_size));
	std::strncpy(const_cast<char*>(error_message), bytes_number_buffer, sizeof(bytes_number_buffer));

	return error_message;
}

}

