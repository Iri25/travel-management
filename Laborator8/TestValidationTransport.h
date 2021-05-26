#pragma once
#ifndef TEST_VALIDATION_TRANSPORT_H
#define TEST_VALIDATION_TRANSPORT_H
#include "Transport.h"
#include "ValidationTransport.h"

class TestValidationTransport
{
private:
	ValidationTransport* validation;
	void testValidationTransport();
public:
	TestValidationTransport();
	~TestValidationTransport();

	void runTestValidationTransport();
};

#endif