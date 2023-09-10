
#pragma once

#include <gtest/gtest.h>
#include <template/Hello.hpp>

namespace template_namespace::unit_test
{

class HelloTestFixture : template_namespace::Hello
{
public:
	MOCK_METHOD(void, echo_world, ());
};

}

