#include "TestBus.h"
#include <assert.h>

TestBus::TestBus()
{
}

TestBus::~TestBus()
{
}

void TestBus::testImplicitConstructor()
{
	Bus bus;
	assert(bus.getCode().empty());
	assert(bus.getArrivalLocation().empty());
	assert(bus.getDeppartureLocation().empty());
	assert(bus.getTotalNumberOfSeats() == 0);
	assert(bus.getNumberOfReservedSeats() == 0);
	assert(bus.getNumberOfTravelDays() == 0);
}

void TestBus::testConstructorWithParameters()
{
	Bus bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	assert(bus.getCode() == "1143");
	assert(bus.getArrivalLocation() == "Suceava");
	assert(bus.getDeppartureLocation() == "Cluj");
	assert(bus.getTotalNumberOfSeats() == 40);
	assert(bus.getNumberOfReservedSeats() == 36);
	assert(bus.getNumberOfTravelDays() == 1);
}

void TestBus::testCopyConstructor()
{
	Bus bus1("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	Bus bus2(bus1);
	assert(bus1.getCode() == bus2.getCode());
	assert(bus1.getArrivalLocation() == bus2.getArrivalLocation());
	assert(bus1.getDeppartureLocation() == bus2.getDeppartureLocation());
	assert(bus1.getTotalNumberOfSeats() == bus2.getTotalNumberOfSeats());
	assert(bus1.getNumberOfReservedSeats() == bus2.getNumberOfReservedSeats());
	assert(bus1.getNumberOfTravelDays() == bus2.getNumberOfTravelDays());
}

void TestBus::testClone()
{
	Bus bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	Bus* busClone = (Bus*)bus.clone();
	assert(bus == *busClone);
	assert(&bus != busClone);
}

void TestBus::testAssignmentOperator()
{
	Bus bus1("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	Bus bus2(bus1);
	bus2 = bus1;
	assert(bus1.getCode() == bus2.getCode());
	assert(bus1.getArrivalLocation() == bus2.getArrivalLocation());
	assert(bus1.getDeppartureLocation() == bus2.getDeppartureLocation());
	assert(bus1.getTotalNumberOfSeats() == bus2.getTotalNumberOfSeats());
	assert(bus1.getNumberOfReservedSeats() == bus1.getNumberOfReservedSeats());
	assert(bus1.getNumberOfTravelDays() == bus2.getNumberOfTravelDays());
}

void TestBus::testEqualityOperator()
{
	Bus bus1("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	Bus bus2 = bus1;
	assert(bus1 == bus2);
	bus2.setCode(bus1.getCode());
	assert(bus1 == bus2);
	bus2.setArrivalLocation(bus1.getArrivalLocation());
	assert(bus1 == bus2);
	bus2.setDeppartureLocation(bus1.getDeppartureLocation());
	assert(bus1 == bus2);
	bus2.setTotalNumberOfSeats(bus1.getTotalNumberOfSeats());
	assert(bus1 == bus2);
	bus2.setNumberOfReservedSeats(bus1.getNumberOfReservedSeats());
	assert(bus1 == bus2);
	bus2.setNumberOfTravelDays(2);
	assert(bus1 == bus2);
}

void TestBus::testGetNumberOfTravelDays()
{
	Bus bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	assert(bus.getNumberOfTravelDays() == 1);
}

void TestBus::testSettNumberOfTravelDays()
{
	Bus bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	bus.setNumberOfTravelDays(2);
	assert(bus.getNumberOfTravelDays() == 2);
}

void TestBus::testToString()
{
	Bus bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	assert(bus.toString(" ") == "Autobuz 1143 Suceava Cluj 11.11.2020 40 36 1");
	assert(bus.toString(",") == "Autobuz,1143,Suceava,Cluj,11.11.2020,40,36,1");
}

void TestBus::runTestBus()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testGetNumberOfTravelDays();
	this->testSettNumberOfTravelDays();
	this->testToString();
}