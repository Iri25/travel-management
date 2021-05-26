#pragma pragma 
#ifndef TEST_H
#define TEST_H
#include "Service.h"

class Tests
{
private:
	Service* service;
	ValidationTransport* validation;

	void test();
public:
	Tests();
	~Tests();

	void runTest();
};
#endif