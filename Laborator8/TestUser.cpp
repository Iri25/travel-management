#include "TestUser.h"
#include <cassert>

TestUser::TestUser()
{
}

TestUser::~TestUser()
{
}

void TestUser::testImplicitConstructor()
{
	User user;
	assert(user.getUserName().empty());
	assert(user.getPassword().empty());
}

void TestUser::testConstructorWithParameters()
{
	User user("irina14", "ai2000");
	assert(user.getUserName() == "irina14");
	assert(user.getPassword() == "ai2000");
}

void TestUser::testCopyConstructor()
{
	User user1("irina14", "ai2000");
	User user2(user1);
	assert(user1.getUserName() == user2.getUserName());
	assert(user1.getPassword() == user2.getPassword());
}

void TestUser::testAssignmentOperator()
{
	User user1("irina14", "ai2000");
	User user2(user1);
	user1 == user2;
	assert(user1.getUserName() == user2.getUserName());
	assert(user1.getPassword() == user2.getPassword());
}

void TestUser::testEqualityOperator()
{
	User user1("irina14", "ai2000");
	User user2 = user1;
	assert(user1 == user2);
	user2.setUserName(user1.getUserName());
	assert(user1 == user2);
	user2.setPassword(user1.getUserName());
	assert(user1 == user2);
}

void TestUser::testGetUserName()
{
	User user("irina14", "ai2000");
	assert(user.getUserName() == "irina14");
}

void TestUser::testGetPassword()
{
	User user("irina14", "ai2000");
	assert(user.getPassword() == "ai2000");
}

void TestUser::testSetUserName()
{
	User user;
	user.setUserName("miraS05");
	assert(user.getUserName() == "miraS05");
}

void TestUser::testSetPassword()
{
	User user;
	user.setPassword("acs05");
	assert(user.getPassword() == "acs05");
}

void TestUser::testToString()
{
	User user("irina14", "ai2000");
	assert(user.toString(" ") == "Utilizator irina14 ai2000");
}

void TestUser::runTestUser()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testGetUserName();
	this->testGetPassword();
	this->testSetUserName();
	this->testSetPassword();
	this->testToString();
}