#include "TestValidationAirPlane.h"
#include "ValidationException.h"
#include <cassert>

TestValidationAirPlane::TestValidationAirPlane()
{
}

TestValidationAirPlane::~TestValidationAirPlane()
{
}

void TestValidationAirPlane::testValidationAirPlane()
{
	this->validation = new ValidationAirPlane();
	AirPlane* airPlane1 = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 0);
	try
	{
		validation->validate(airPlane1);
	}
	catch(ValidationException& exception)
	{
		assert(false);
	}
	AirPlane* airPlane2 = new AirPlane("", "Suceava", "Cluj", "11.11.2020", 40, 36, 0);
	try
	{
		validation->validate(airPlane2);
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
	AirPlane* airPlane3 = new AirPlane("2343", "", "Cluj", "11.11.2020", 40, 36, 0);
	try
	{
		validation->validate(airPlane3);
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
	AirPlane* airPlane4 = new AirPlane("2343", "Suceava", "", "11.11.2020", 40, 36, 0);
	try
	{
		validation->validate(airPlane4);
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
	AirPlane* airPlane5 = new AirPlane("2343", "Suceava", "Cluj", "", 40, 36, 0);
	try
	{
		validation->validate(airPlane5);
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
	AirPlane* airPlane6 = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", -40, 36, 0);
	try
	{
		validation->validate(airPlane6);
	}
	catch(ValidationException & exception)
	{
		assert(false);
	}
	AirPlane* airPlane7 = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, -36, 0);
	try
	{
		validation->validate(airPlane7);
	}
	catch(ValidationException & exception)
	{
		assert(false);
	}
}

void TestValidationAirPlane::runTestValidationAirPlane()
{
	this->testValidationAirPlane();
}
