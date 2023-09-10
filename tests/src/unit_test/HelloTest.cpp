/**
 * @copyright Andrey Borisovich Quality Technologies
 * SPDX - License - Identifier: Apache - 2.0
*/

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <template/unit_test/HelloTestFixture.hpp>

using ::testing::StrictMock;

namespace template_namespace::unit_test
{

// Demonstrate some basic assertions.
TEST(HelloTest, HelloTest)
{
	StrictMock<template_namespace::unit_test::HelloTestFixture> greetingMock;
	EXPECT_CALL(greetingMock, echo_world());

	greetingMock.echo_world();
}

}
