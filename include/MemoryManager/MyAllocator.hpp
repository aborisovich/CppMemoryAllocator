/**
 * @file MyAllocator.hpp
 * @copyright 2023 Andrey Borisovich. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * @author Andrey Borisovich
 */
#include <MemoryManager/HeapMemoryTracker.hpp>
#include <cstdlib>
#include <new>
#include <limits>
#include <iostream>
#include <vector>

#pragma once

namespace memory_manager
{
/**
 * @brief Stateless custom allocator.
 * Fulfills C++ named requirements for Allocator.
 * Based on example from https://en.cppreference.com/w/cpp/named_req/Allocator#Allocator_completeness_requirements
 */
template<class T>
class MyAllocator : public HeapMemoryTracker
{
public:
	/**
	 * @brief Aliased T as value type - part of C++ requirements for Allocator.
	 */
	typedef T value_type;

	/**
	 * @brief Meets requirements C++ Allocator named requirements
	 * about relationship between instances:
	 * - default constructible
	 * - copy constructible
	 * - move constructible
	 * - copy assignable
	 * - move assignable
	 * @note Those ctors and operators do nothing due to stateless
	 * implementation.
	 */
	MyAllocator() = default;
	template<class U>
	constexpr MyAllocator(const MyAllocator<U>&) noexcept {}
	template<class U>
	constexpr MyAllocator(MyAllocator<U>&&) noexcept {}
	template<class U>
	constexpr MyAllocator operator=(const MyAllocator<U>& other) noexcept {}
	template<class U>
	constexpr MyAllocator operator=(MyAllocator<U>&& other) noexcept {}
	~MyAllocator() = default;

	/**
	 * @brief Allocates storage suitable for an array object of type T[n]
	 * and creates the array, but does not construct array elements.
	 * @param size Number of array elements.
	 * @return Pointer to allocated storage.
	 */
	[[nodiscard]] T* allocate(std::size_t size) requires (!std::is_void_v<T>)
	{
		if(size > std::numeric_limits<std::size_t>::max() / sizeof(T))
			throw std::bad_array_new_length();

		long long int alloc_size = size * sizeof(T);

		reserve_memory(alloc_size);

		auto memory = static_cast<T*>(std::malloc(alloc_size));
		if(memory == nullptr)
		{
			release_memory(alloc_size);
			throw std::bad_alloc();
		}

		report(memory, size);

		return memory;
	}

	/**
	 * @brief Allocates storage suitable for an array object of void*,
	 * does not construct array elements.
	 * @param size Amount of memory in bytes to allocate.
	 * @return Pointer to allocated storage.
	 */
	[[nodiscard]] void* allocate(std::size_t size)
	{
		reserve_memory(size);
		void* memory = std::malloc(size);
		if(memory == nullptr)
		{
			release_memory(size);
			throw std::bad_alloc();
		}

		report(memory, size);

		return memory;
	}

	/**
	 * @brief Deallocates storage pointed to obj, which must be a value returned by a previous call to allocate.
	 * @param obj Object to deallocate memory for.
	 * @param size Number of array elements.
	 */
	void deallocate(T* obj, std::size_t size) noexcept requires (!std::is_void_v<T>)
	{
		report(obj, size, false);
		release_memory(size * sizeof(T));
		std::free(obj);
	}

	/**
	 * @brief Deallocates storage pointed to obj, which must be a value returned by a previous call to allocate
	 * for void* objects.
	 * @param obj Object to deallocate memory for.
	 * @param size Amount of memory in bytes to deallocate.
	 */
	void deallocate(void* obj, std::size_t size) noexcept
	{
		report(obj, size, false);
		release_memory(size);
		std::free(obj);
	}

private:

	/**
	 * @brief Reports how many bytes are being allocated or freed at the object address.
	 * @tparam Ptr Template parameter type that must be a pointer type.
	 * @param obj
	*/
	template<typename Ptr>
	static void report(Ptr obj, std::size_t size, bool alloc = true) requires std::is_pointer_v<Ptr>
	{
		std::cout << (alloc ? "Allocated: " : "Deallocated: ") << sizeof(Ptr) * size
			<< " bytes at " << std::hex << std::showbase
			<< reinterpret_cast<void*>(obj) << std::dec << '\n';
	}

	friend void* ::operator new(std::size_t);
	friend void ::operator delete(void* memory, std::size_t size);
};

template<typename T, typename U>
bool operator==(const MyAllocator <T>&, const MyAllocator <U>&) { return true; }

template<typename T, typename U>
bool operator!=(const MyAllocator <T>&, const MyAllocator <U>&) { return false; }
}

