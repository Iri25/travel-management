#include "TestValidationTransport.h"
#include "ValidationTransport.h"
#include "ValidationException.h"
#include <cassert>

TestValidationTransport::TestValidationTransport()
{
}

TestValidationTransport::~TestValidationTransport()
{
}

void TestValidationTransport::testValidationTransport()
{
	this->validation = new ValidationTransport();
	Transport* transport1 = new Transport("1143", "Suceava", "Cluj", "11.11.2020", 40, 36);
	try
	{
		validation->validate(transport1);
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
	Transport* transport2 = new Transport("", "Suceava", "Cluj", "11.11.2020", 40, 36);
	try
	{
		validation->validate(transport2);
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
	Transport* transport3 = new Transport("1143", "", "Cluj", "11.11.2020", 40, 36);
	try
	{
		validation->validate(transport3);
	}
	catch(ValidationException & exception)
	{
		assert(false);
	}
	Transport* transport4 = new Transport("1143", "Suceava", "", "11.11.2020", 40, 36);
	try
	{
		validation->validate(transport4);
	}
	catch(ValidationException & exception)
	{
		assert(false);
	}
	Transport* transport5 = new Transport("1143", "Suceava", "Cluj", "", 40, 36);
	try
	{
		validation->validate(transport5);
	}
	catch(ValidationException & exception)
	{
		assert(false);
	}
	Transport* transport6 = new Transport("1143", "Suceava", "Cluj", "11.11.2020", -40, 36);
	try
	{
		validation->validate(transport6);
	}
	catch(ValidationException & exception)
	{
		assert(false);
	}
	Transport* transport7 = new Transport("1143", "Suceava", "Cluj", "11.11.2020", 40, -36);
	try
	{
		validation->validate(transport7);
	}
	catch (ValidationException & exception)
	{
		assert(false);
	}
}

void TestValidationTransport::runTestValidationTransport()
{
	this->testValidationTransport();
}