#include "TestException.h"
#include <cassert>
#include "DeleteException1.h"
#include "DeleteException2.h"
#include <iostream>

TestException::TestException()
{
}

TestException::~TestException()
{
}

void TestException::testException()
{
	
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	repositoryFileTransport->loadFromFile();
	AirPlane* c1 = new AirPlane("156", "Cluj-Napoca", "Dubai", "14.06.2020", 100, 80, 0);
	Bus* c2 = new Bus("873", "Constanta", "Brasov", "15.07.2020", 40, 20, 1);
	Bus* c3 = new Bus("118", "Bucuresti", "Vienna", "11.06.2020", 80, 50, 3);
	service->addAirPlane(c1);
	service->addBus(c2);
	service->addBus(c3);

	try
	{
		service->deleteTransport1("873", "Brasov");
		assert(service->getSizeTransport() == 2);
		assert(*service->getTransport(0) == *c1);
		assert(*service->getTransport(1) == *c3);
	}
	catch(DeleteException1& exception)
	{
		//cout << "DeleteException1 thrown! ";
		assert (false);
	}
	catch (DeleteException2& exception)
	{
		//cout << "DeleteException2 thrown! ";
		assert(false);
	}

	try
	{
		service->deleteTransport1("156", "Paris");
		assert(false);
	}
	catch(DeleteException1& exception)
	{
		//cout << "DeleteException1 thrown! ";
		assert(service->getSizeTransport() == 2);
		assert(*service->getTransport(0) == *c1);
		assert(*service->getTransport(1) == *c3);
	}
	catch (DeleteException2 & exception)
	{
		assert(false);
	}
	
	try
	{
		service->deleteTransport1("667", "Fagaras");
		assert (false);
	}
	catch(DeleteException1& exception)
	{
		assert(false); 
	}
	catch(DeleteException2& exception)
	{
		//cout << "DeleteException2 thrown! ";
		assert(service->getSizeTransport() == 2);
		assert(*service->getTransport(0) == *c1);
		assert(*service->getTransport(1) == *c3);
	}

	try
	{
		service->deleteTransport1("157", "Paris");
		assert (false);
	}
	catch(DeleteException2& exception)
	{
		//cout << "DeleteException2 thrown! ";
	}
	catch(DeleteException1& exception)
	{
		assert(false);
	}

	try
	{
		service->deleteTransport1("667", "Fagaras");
		assert(false);
	}
	catch(DeleteException2& exception)
	{
		//cout << "DeleteException2 thrown! ";
	}
	catch (DeleteException1& exception)
	{
		assert(false);
	}
}

void TestException::runTestException()
{
	this->testException();
}