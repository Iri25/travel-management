#pragma once
#ifndef TEST_BUS_H
#define TEST_BUS_H
#include "Bus.h"
#include <ostream>

using namespace std;

class TestBus
{
private:
	Bus bus;

	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();

	void testClone();

	void testAssignmentOperator();
	void testEqualityOperator();

	void testGetNumberOfTravelDays();

	void testSettNumberOfTravelDays();

	void testToString();
public:
	TestBus();
	~TestBus();

	void runTestBus();
};

#endif 