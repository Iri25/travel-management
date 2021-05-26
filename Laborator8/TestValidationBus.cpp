#include "TestValidationBus.h"
#include "ValidationException.h"
#include <cassert>

TestValidationBus::TestValidationBus()
{
}

TestValidationBus::~TestValidationBus()
{
}

void TestValidationBus::runTestValidationBus()
{
	this->validation = new ValidationBus();
	Bus* bus1 = new Bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	try
	{
		validation->validate(bus1);
	}
	catch(ValidationException& exception)
	{
		assert(false);
	}
	Bus* bus2 = new Bus("", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	try
	{
		validation->validate(bus2);
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
	Bus* bus3 = new Bus("1143", "", "Cluj", "11.11.2020", 40, 36, 1);
	try
	{
		validation->validate(bus3);
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
	Bus* bus4 = new Bus("1143", "Suceava", "", "11.11.2020", 40, 36, 1);
	try
	{
		validation->validate(bus4);
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
	Bus* bus5 = new Bus("1143", "Suceava", "Cluj", "", 40, 36, 1);
	try
	{
		validation->validate(bus5);
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
	Bus* bus6 = new Bus("1143", "Suceava", "Cluj", "11.11.2020", -40, 36, 1);
	try
	{
		validation->validate(bus6);
	}
	catch(ValidationException& exception)
	{
		assert(false);
	}
	Bus* bus7 = new Bus("1143", "Suceava", "Cluj", "11.11.2020", 40, -36, 1);
	try
	{
		validation->validate(bus7);
	}
	catch(ValidationException& exception)
	{
		assert(false);
	}
	Bus* bus8 = new Bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, -1);
	try
	{
		validation->validate(bus8);
	}
	catch(ValidationException& exception)
	{
		assert(false);
	}
}

void TestValidationBus::testValidationBus()
{
	this->runTestValidationBus();
}