#pragma once
#ifndef TEST_AIR_PLANE_H
#define TEST_AIR_PLANE_H
#include "AirPlane.h"

class TestAirPlane
{
private:
	AirPlane airPlane;

	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();

	void testClone();

	void testAssignmentOperator();
	void testEqualityOperator();

	void testGetLayover();

	void testSetLayover();

	void testToString();
public:
	TestAirPlane();
	~TestAirPlane();

	void runTestAirPlane();
};

#endif 