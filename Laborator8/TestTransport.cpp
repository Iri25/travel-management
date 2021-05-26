#include "TestTransport.h"
#include <assert.h>

TestTransport::TestTransport()
{
}

TestTransport::~TestTransport()
{
}

void TestTransport::testImplicitConstructor()
{
	Transport transport;
	assert(transport.getCode().empty());
	assert(transport.getArrivalLocation().empty());
	assert(transport.getDeppartureLocation().empty());
	assert(transport.getTotalNumberOfSeats() == 0);
	assert(transport.getNumberOfReservedSeats() == 0);
}

void TestTransport::testConstructorWithParameters()
{
	Transport transport("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	assert(transport.getCode() == "1143");
	assert(transport.getArrivalLocation() == "Suceava");
	assert(transport.getDeppartureLocation() == "Cluj");
	assert(transport.getTotalNumberOfSeats() == 40);
	assert(transport.getNumberOfReservedSeats() == 36);
}

void TestTransport::testCopyConstructor()
{
	Transport transport1("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	Transport transport2(transport1);
	assert(transport1.getCode() == transport2.getCode());
	assert(transport1.getArrivalLocation() == transport2.getArrivalLocation());
	assert(transport1.getDeppartureLocation() == transport2.getDeppartureLocation());
	assert(transport1.getTotalNumberOfSeats() == transport2.getTotalNumberOfSeats());
	assert(transport1.getNumberOfReservedSeats() == transport2.getNumberOfReservedSeats());
}

void TestTransport::testClone()
{
	Transport transport("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	Transport* cloneTransport = transport.clone();
	assert(transport == *cloneTransport);
	assert(&transport != cloneTransport);
}

void TestTransport::testAssignmentOperator()
{
	Transport transport1("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	Transport transport2(transport);
	transport2 = transport1;
	assert(transport1.getCode() == transport2.getCode());
	assert(transport1.getArrivalLocation() == transport2.getArrivalLocation());
	assert(transport1.getDeppartureLocation() == transport2.getDeppartureLocation());
	assert(transport1.getTotalNumberOfSeats() == transport2.getTotalNumberOfSeats());
	assert(transport1.getNumberOfReservedSeats() == transport1.getNumberOfReservedSeats());
}

void TestTransport::testEqualityOperator()
{
	Transport transport1("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	Transport transport2 = transport1;
	assert(transport1 == transport2);
	transport2.setCode(transport1.getCode());
	assert(transport1 == transport2);
	transport2.setArrivalLocation(transport1.getArrivalLocation());
	assert(transport1 == transport2);
	transport2.setDeppartureLocation(transport1.getDeppartureLocation());
	assert(transport1 == transport2);
	transport2.setTotalNumberOfSeats(transport1.getTotalNumberOfSeats());
	assert(transport1 == transport2);
	transport2.setNumberOfReservedSeats(transport1.getNumberOfReservedSeats());
	assert(transport1 == transport2);
}

void TestTransport::testGetCode()
{
	Transport transport("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	assert(transport.getCode() == "1143");
}

void TestTransport::testGetArrivalLocation()
{
	Transport transport("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	assert(transport.getArrivalLocation() == "Suceava");
}

void TestTransport::testGetDeppartureLocation()
{
	Transport transport("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	assert(transport.getDeppartureLocation() == "Cluj");
}

void TestTransport::testGetDate()
{
	Transport transport("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	assert(transport.getDate() == "11.11.2020");
}

void TestTransport::testGetTotalNumberOfSeats()
{
	Transport transport("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	assert(transport.getTotalNumberOfSeats() == 40);
}

void TestTransport::testGetNumberOfReservedSeats()
{
	Transport transport("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	assert(transport.getNumberOfReservedSeats() == 36);
}

void TestTransport::testSetCode()
{
	Transport transport;
	transport.setCode("1198");
	assert(transport.getCode() == "1198");
}

void TestTransport::testSetArrivalLocation()
{
	Transport transport;
	transport.setArrivalLocation("Suceava");
	assert(transport.getArrivalLocation() == "Suceava");
}

void TestTransport::testSetDeppartureLocation()
{
	Transport transport;
	transport.setDeppartureLocation("Cluj");
	assert(transport.getDeppartureLocation() == "Cluj");
}

void TestTransport::testSetDate()
{
	Transport transport;
	transport.setDate("05.08.2020");
	assert(transport.getDate() == "05.08.2020");
}

void TestTransport::testSetTotalNumberOfSeats()
{
	Transport transport;
	transport.setTotalNumberOfSeats(40);
	assert(transport.getTotalNumberOfSeats() == 40);
}

void TestTransport::testSetNumberOfReservedSeats()
{
	Transport transport;
	transport.setNumberOfReservedSeats(36);
	assert(transport.getNumberOfReservedSeats() == 36);
}

void TestTransport::testToString()
{
	Transport transport("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	assert(transport.toString(" ") == "1143 Suceava Cluj 11.11.2020 40 36");
	assert(transport.toString(",") == "1143,Suceava,Cluj,11.11.2020,40,36");
}

void TestTransport::runTestTransport()
{
	this->testImplicitConstructor();
	this->testConstructorWithParameters();
	this->testCopyConstructor();
	this->testClone();
	this->testAssignmentOperator();
	this->testEqualityOperator();
	this->testGetCode();
	this->testGetArrivalLocation();
	this->testGetDeppartureLocation();
	this->testGetDate();
	this->testGetTotalNumberOfSeats();
	this->testGetNumberOfReservedSeats();
	this->testSetCode();
	this->testSetArrivalLocation();
	this->testSetDeppartureLocation();
	this->testSetDate();
	this->testSetTotalNumberOfSeats();
	this->testSetNumberOfReservedSeats();
	this->testToString();
}