#pragma once
#ifndef TEST_USER_H
#define TEST_USER_H
#include "User.h"
#include <ostream>

using namespace std;

class TestUser
{
private:
	User user;

	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();

	void testAssignmentOperator();
	void testEqualityOperator();

	void testGetUserName();
	void testGetPassword();

	void testSetUserName();
	void testSetPassword();

	void testToString();
public:
	TestUser();
	~TestUser();

	void runTestUser();
};

#endif 