/**
 * @file MyAllocatorUnitTest.cpp
 * @copyright 2023 Andrey Borisovich. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * @author Andrey Borisovich
 */
#include <MemoryManager/HeapMemoryTracker.hpp>
#include <MemoryManager/PoolOutOfMemoryException.hpp>
#include <gtest/gtest.h>
#include <limits>
#include <random>

namespace unit_test
{

class MyAllocatorUnitTest : public ::testing::TestWithParam<int>
{
};

std::vector<int> get_random_numbers()
{
	std::vector<int> test_values;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> rand;
	rand = std::uniform_int_distribution<>(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
	for(uint16_t test_iteration = 0; test_iteration < 20; test_iteration++)
		test_values.push_back(rand(gen));
	return test_values;
}

INSTANTIATE_TEST_SUITE_P(Numerical,
	MyAllocatorUnitTest,
	testing::ValuesIn(get_random_numbers()));

TEST_P(MyAllocatorUnitTest, integerAllocation)
{
	std::size_t memory_amount_before = memory_manager::HeapMemoryTracker::get_available_memory();
	int number = GetParam();
	int* ptr = new int(number);
	std::size_t memory_amount_after = memory_manager::HeapMemoryTracker::get_available_memory();
	ASSERT_TRUE(ptr != nullptr);
	ASSERT_EQ(memory_amount_before - sizeof(number), memory_amount_after);
}

}
