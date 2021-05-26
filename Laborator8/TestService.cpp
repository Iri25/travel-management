#include "Service.h"
#include "TestService.h"
#include "ValidationAirPlane.h"
#include "ValidationBus.h"
#include "Exception.h"
#include "ValidationException.h"
#include <cassert>
#include <iostream>

TestService::TestService()
{
	Transport* airPlane = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	Transport* bus = new Bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	this->transportsIn.push_back(airPlane);
	this->transportsIn.push_back(bus);
}

TestService::~TestService()
{
}

void TestService::testAddTransport()
{
	ValidationTransport* validationAirPlane = new ValidationAirPlane();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	AirPlane* airPlane = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	try
	{
		service->addAirPlane(airPlane);
		assert(*service->getTransport(0) == *airPlane);
	}
	catch(ValidationException & exception)
	{
		assert(false);
	}
}

void TestService::testUpdateTransport()
{
	ValidationTransport* validationAirPlane = new ValidationAirPlane();
	ValidationTransport* validationBus = new ValidationBus();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	AirPlane* airPlane1 = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	service->addAirPlane(airPlane1);
	AirPlane* airPlane2 = new AirPlane("2923", "Bucuresti", "Madrid", "05.05.2020", 200, 100, 1);
	try
	{
		service->updateAirPlane(airPlane1, airPlane2);
		assert(*service->getTransport(0) == *airPlane2);
	}
	catch (Exception & exception)
	{
		assert(false);
	}
}

void TestService::testDeleteTransport()
{
	ValidationTransport* validationAirPlane = new ValidationAirPlane();
	ValidationTransport* validationBus = new ValidationBus();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	AirPlane* airPlane1 = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	service->addAirPlane(airPlane1);
	Transport* airPlane2 = new AirPlane("2923", "Bucuresti", "Madrid", "05.05.2020", 200, 100, 1);
	if(service->findTransport(airPlane2) != -1)
		service->deleteTransport(airPlane2);
	assert(service->getSizeTransport() == 1);
	assert(*service->getTransport(0) == *airPlane1);
	if(service->findTransport(airPlane1) != -1)
		service->deleteTransport(airPlane1);
	assert(service->getSizeTransport() == 0);
}

void TestService::testGetAllTransport()
{
	ValidationTransport* validationAirPlane = new ValidationAirPlane();
	ValidationTransport* validationBus = new ValidationBus();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	AirPlane* airPlane = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	Bus* bus = new Bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	service->addAirPlane(airPlane);
	service->addBus(bus);
	vector<Transport*> transports = service->getAllTransport();
	assert(*transports[0] == *airPlane->clone());
	assert(*transports[1] == *bus->clone());
}

void TestService::testGetSizeTransport()
{
	ValidationTransport* validationAirPlane = new ValidationAirPlane();
	ValidationTransport* validationBus = new ValidationBus();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	assert(service->getSizeTransport() == 0);
	Bus* bus = new Bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	service->addBus(bus);
	assert(service->getSizeTransport() == 1);
}

void TestService::testGetTransport()
{
	ValidationTransport* validationAirPlane = new ValidationAirPlane();
	ValidationTransport* validationBus = new ValidationBus();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	AirPlane* airPlane = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	service->addAirPlane(airPlane);
	assert(*service->getTransport(0) == *airPlane->clone());
	assert(*service->getTransport(-1) == *(new Transport()));
	assert(*service->getTransport(1) == *(new Transport()));
}

void TestService::testFindTransport()
{
	ValidationTransport* validationAirPlane = new ValidationAirPlane();
	ValidationTransport* validationBus = new ValidationBus();
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	AirPlane* airPlane = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	service->addAirPlane(airPlane);
	assert(service->findTransport(airPlane) != -1);
	assert(service->findTransport(airPlane) == 0);
}

void TestService::testAddUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user("irina14", "ai2000");
	service->addUser(user);
	assert(service->getUser(0) == user);
}

void TestService::testUpdateUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user1("irina14", "ai2000");
	service->addUser(user1);
	User user2("teodor.pop2008", "bw2008");
	assert(service->getUser(0) == user1);
	service->updateUser(user1, user2);
	assert(service->getUser(0) == user2);
}

void TestService::testDeleteUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user1("irina14", "ai2000");
	service->addUser(user1);
	User user2("teodor.pop2008", "bw2008");
	if(service->findUser(user2) != -1)
		service->deleteUser(user2);
	assert(service->getSizeUser() == 1);
	assert(service->getUser(0) == user1);
	service->deleteUser(user1);
	assert(service->getSizeUser() == 0);
}

void TestService::testGetAllUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user("irina14", "ai2000");
	service->addUser(user);
	vector<User> users = service->getAllUser();
	assert(users[0] == user);
}

void TestService::testGetSizeUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	assert(service->getSizeUser() == 0);
}

void TestService::testGetUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user1("irina14", "ai2000");
	service->addUser(user1);
	assert(service->getUser(0) == user1);
	User user2("teodor.pop2008", "bw2008");
	service->addUser(user2);
	assert(service->getUser(1) == user2);
}

void TestService::testFindUser()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	User user("irina14", "ai2000");
	service->addUser(user);
	assert(service->findUser(user) != -1);
	assert(service->findUser(user) == 0);
}

void TestService::testRegistration()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	User user("irina14", "ai2000");
	service->registration(user);
	assert(repositoryFileUser.findItem(user));
}

void TestService::testLogin()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	User user("irina14", "ai2000");
	if(service->findUser(user) != -1)
		service->login(user);
	assert(repositoryFileUser.findItem(user));
}

void TestService::testSearch()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	AirPlane* airPlane1 = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	service->addAirPlane(airPlane1);
	AirPlane* airPlane2 = new AirPlane("2923", "Bucuresti", "Madrid", "05.05.2020", 200, 100, 1);
	service->addAirPlane(airPlane2);
	string date = "11.11.2020";
	Transport* filterTransportsByDate[100];
	int lenght = 0, i;
	service->search(date, filterTransportsByDate, lenght);
	for (i = 0; i < lenght; i++)
	{
		assert(filterTransportsByDate[i]->getDate() == date);
	}
	assert(lenght == 1);
}

void TestService::testBuy()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV();
	RepositoryFileUser repositoryFileUser;
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	service->setRepository(repositoryFileTransport, repositoryFileUser);
	AirPlane* airPlane1 = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	service->addAirPlane(airPlane1);
	AirPlane* airPlane2 = new AirPlane("2923", "Bucuresti", "Madrid", "05.05.2020", 200, 100, 1);
	service->addAirPlane(airPlane2);
	string code = "2343";
	int numberOfReservedSeats = 3, i;
	service->reservation(code, numberOfReservedSeats);
	for (i = 0; i < service->getSizeTransport(); i++)
	{
		if (service->getTransport(i)->getCode() == "2343")
		{
			assert(service->getTransport(i)->getNumberOfReservedSeats() == 39);
		}
	}
}

void TestService::runTestService()
{
	this->testAddTransport();
	this->testUpdateTransport();
	this->testDeleteTransport();
	this->testGetAllTransport();
	this->testGetSizeTransport();
	this->testGetTransport();
	this->testFindTransport();
	this->testAddUser();
	this->testUpdateUser();
	this->testDeleteUser();
	this->testGetAllUser();
	this->testGetSizeUser();
	this->testGetUser();
	this->testFindUser();
	this->testRegistration();
	this->testLogin();
	this->testSearch();
	this->testBuy();
}