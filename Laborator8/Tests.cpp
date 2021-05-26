#include "Tests.h"
#include <cassert>
#include "Transport.h"
#include <iostream>

Tests::Tests()
{
}

Tests::~Tests()
{
}

void Tests::test()
{
	
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	AirPlane* c1 = new AirPlane("156", "ClujNapoca", "Dubai", "14.06.2020", 100, 80, 0);
	Bus* c2 = new Bus("873", "Constanta", "Brasov", "15.07.2020", 40, 20, 1);
	Bus* c3 = new Bus("118", "Viena", "Bucuresti", "14.06.2020", 80, 50, 3);
	AirPlane* c4 = new AirPlane("112", "Bucuresti", "ClujNapoca", "14.06.2020", 100, 80, 0);
	AirPlane* c5 = new AirPlane("112", "ClujNapoca", "Bucuresti", "14.06.2020", 100, 80, 0);

	service->emptyService();
	service->addAirPlane(c1);
	service->addBus(c2);
	service->addBus(c3);
	service->addAirPlane(c4);
	service->addAirPlane(c5);
	service->deleteTransport2(c1);
	assert(service->getSizeTransport() == 3);
	assert(*service->getTransport(0) == *c2);
	assert(*service->getTransport(1) == *c3);
	assert(*service->getTransport(2) == *c5);

	
	service->emptyService();
	service->addAirPlane(c1);
	service->addBus(c2);
	service->addBus(c3);
	service->addAirPlane(c4);
	service->addAirPlane(c5); 
	service->deleteTransport2(c2);
	assert(service->getSizeTransport() == 4);
	assert(*service->getTransport(0) == *c1);
	assert(*service->getTransport(1) == *c3);
	assert(*service->getTransport(2) == *c4);
	assert(*service->getTransport(3) == *c5);

	service->emptyService();
	service->addAirPlane(c1);
	service->addBus(c2);
	service->addBus(c3);
	service->addAirPlane(c4);
	service->addAirPlane(c5);
	service->deleteTransport2(c3);
	assert(service->getSizeTransport() == 3);
	assert(*service->getTransport(0) == *c1);
	assert(*service->getTransport(1) == *c2);
	assert(*service->getTransport(2) == *c5);


	service->emptyService();
	service->addAirPlane(c1);
	service->addBus(c2);
	service->addBus(c3);
	service->addAirPlane(c4);
	service->addAirPlane(c5);
	service->deleteTransport2(c4);
	assert(service->getSizeTransport() == 1);
	assert(*service->getTransport(0) == *c2);
	
	service->emptyService();
	service->addAirPlane(c1);
	service->addBus(c2);
	service->addBus(c3);
	service->addAirPlane(c4);
	service->addAirPlane(c5);
	service->deleteTransport2(c5);
	assert(service->getSizeTransport() == 3);
	assert(*service->getTransport(0) == *c1);
	assert(*service->getTransport(1) == *c2);
	assert(*service->getTransport(2) == *c3);
}

void Tests::runTest()
{
	this->test();
}
