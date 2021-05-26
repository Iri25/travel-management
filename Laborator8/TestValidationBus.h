#pragma once
#ifndef TEST_VALIDATION_BUS_H
#define TEST_VALIDATION_BUS_H
#include "Bus.h"
#include "ValidationBus.h"

class TestValidationBus
{
private:
	ValidationTransport* validation;

	void testValidationBus();
public:
	TestValidationBus();
	~TestValidationBus();

	void runTestValidationBus();
};

#endif