#pragma once
#ifndef TEST_TRANSPORT_H
#define TEST_TRANSPORT_H
#include "Transport.h"

class TestTransport
{
private:
	Transport transport;

	void testImplicitConstructor();
	void testConstructorWithParameters();
	void testCopyConstructor();

	void testClone();

	void testAssignmentOperator();
	void testEqualityOperator();

	void testGetCode();
	void testGetArrivalLocation();
	void testGetDeppartureLocation();
	void testGetDate();
	void testGetTotalNumberOfSeats();
	void testGetNumberOfReservedSeats();

	void testSetCode();
	void testSetArrivalLocation();
	void testSetDeppartureLocation();
	void testSetDate();
	void testSetTotalNumberOfSeats();
	void testSetNumberOfReservedSeats();

	void testToString();
public:
	TestTransport();
	~TestTransport();

	void runTestTransport();
};

#endif 