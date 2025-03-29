/**
 * @file main.cpp
 * @copyright 2023 Andrey Borisovich. All rights reserved.
 * SPDX-License-Identifier: Apache-2.0
 * @author Andrey Borisovich
 */
#include <memory>
#include <MemoryManager/MyAllocator.hpp>
#include <vector>
#include <cstddef>
#include <array>

static const int a = 30;

struct DemoStruct
{
	int a;
	int b;
};

class DemoClass
{
public:
	const std::string name = "DemoClass name";
	const uint16_t age = 40;

private:
	std::array<std::byte, 256> payload {};
};

int main()
{
	std::vector<int, memory_manager::MyAllocator<int>> numbers;
	std::cout << "Vector push_back int heap allocates:\n";
	numbers.push_back(24);

	std::cout << "unique_ptr to two int struct heap allocates:\n";
	std::unique_ptr<DemoStruct> struct_ptr = std::make_unique<DemoStruct>();

	std::cout << "unique_ptr to class with data heap allocates:\n";
	std::unique_ptr<DemoClass> class_ptr = std::make_unique<DemoClass>();

	std::cout << "Observe how vector of numbers expands:\n";
	for(int i=0; i<100; i++)
	{
		std::cout << "Vector push_back iteration " << i << std::endl;
		numbers.push_back(i);
	}

	return 0;
}
