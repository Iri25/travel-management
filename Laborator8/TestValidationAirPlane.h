#pragma once
#ifndef TEST_VALIDATION_AIR_PLANE_H
#define TEST_VALIDATION_AIR_PLANE_H
#include "AirPlane.h"
#include "ValidationAirPlane.h"

class TestValidationAirPlane
{
private:
	ValidationTransport* validation;

	void testValidationAirPlane();
public:
	TestValidationAirPlane();
	~TestValidationAirPlane();

	void runTestValidationAirPlane();
};

#endif