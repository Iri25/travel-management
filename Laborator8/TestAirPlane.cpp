#include "TestAirPlane.h"
#include <cassert>

TestAirPlane::TestAirPlane()
{
}

TestAirPlane::~TestAirPlane()
{
}

void TestAirPlane::testImplicitConstructor()
{
	AirPlane airPlane;
	assert(airPlane.getCode().empty());
	assert(airPlane.getArrivalLocation().empty());
	assert(airPlane.getDeppartureLocation().empty());
	assert(airPlane.getTotalNumberOfSeats() == 0);
	assert(airPlane.getNumberOfReservedSeats() == 0);
	assert(airPlane.getLayover() == 0);
}

void TestAirPlane::testConstructorWithParameters()
{
	AirPlane airPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 0);
	assert(airPlane.getCode() == "2343");
	assert(airPlane.getArrivalLocation() == "Suceava");
	assert(airPlane.getDeppartureLocation() == "Cluj");
	assert(airPlane.getTotalNumberOfSeats() == 40);
	assert(airPlane.getNumberOfReservedSeats() == 36);
	assert(airPlane.getLayover() == 0);
}

void TestAirPlane::testCopyConstructor()
{
	AirPlane airPlane1("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 0);
	AirPlane airPlane2(airPlane1);
	assert(airPlane1.getCode() == airPlane2.getCode());
	assert(airPlane1.getArrivalLocation() == airPlane2.getArrivalLocation());
	assert(airPlane1.getDeppartureLocation() == airPlane2.getDeppartureLocation());
	assert(airPlane1.getTotalNumberOfSeats() == airPlane2.getTotalNumberOfSeats());
	assert(airPlane1.getNumberOfReservedSeats() == airPlane2.getNumberOfReservedSeats());
	assert(airPlane1.getLayover() == airPlane2.getLayover());
}

void TestAirPlane::testClone()
{
	AirPlane airPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 0);
	AirPlane* airPlaneClone = (AirPlane*)airPlane.clone();
	assert(airPlane == *airPlaneClone);
	assert(&airPlane != airPlaneClone);
}

void TestAirPlane::testAssignmentOperator()
{
	AirPlane airPlane1("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 0);
	AirPlane airPlane2(airPlane1);
	airPlane2 = airPlane1;
	assert(airPlane1.getCode() == airPlane2.getCode());
	assert(airPlane1.getArrivalLocation() == airPlane2.getArrivalLocation());
	assert(airPlane1.getDeppartureLocation() == airPlane2.getDeppartureLocation());
	assert(airPlane1.getTotalNumberOfSeats() == airPlane2.getTotalNumberOfSeats());
	assert(airPlane1.getNumberOfReservedSeats() == airPlane1.getNumberOfReservedSeats());
	assert(airPlane1.getLayover() == airPlane2.getLayover());
}

void TestAirPlane::testEqualityOperator()
{
	AirPlane airPlane1("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 0);
	AirPlane airPlane2 = airPlane1;
	assert(airPlane1 == airPlane2);
	airPlane2.setCode(airPlane1.getCode());
	assert(airPlane1 == airPlane2);
	airPlane2.setArrivalLocation(airPlane1.getArrivalLocation());
	assert(airPlane1 == airPlane2);
	airPlane2.setDeppartureLocation(airPlane1.getDeppartureLocation());
	assert(airPlane1 == airPlane2);
	airPlane2.setTotalNumberOfSeats(airPlane1.getTotalNumberOfSeats());
	assert(airPlane1 == airPlane2);
	airPlane2.setNumberOfReservedSeats(airPlane1.getNumberOfReservedSeats());
	assert(airPlane1 == airPlane2);
	airPlane2.setLayover(1);
	assert(airPlane1 == airPlane2);
}

void TestAirPlane::testGetLayover()
{
	AirPlane airPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 0);
	assert(airPlane.getLayover() == 0);
}

void TestAirPlane::testSetLayover()
{
	AirPlane airPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 0);
	airPlane.setLayover(1);
	assert(airPlane.getLayover() == 1);
}

void TestAirPlane::testToString()
{
	AirPlane airPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 0);
	assert(airPlane.toString(" ") == "Avion 2343 Suceava Cluj 11.11.2020 40 36 0");
	assert(airPlane.toString(",") == "Avion,2343,Suceava,Cluj,11.11.2020,40,36,0");
}

void TestAirPlane::runTestAirPlane()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testGetLayover();
	this->testSetLayover();
	this->testToString();
}