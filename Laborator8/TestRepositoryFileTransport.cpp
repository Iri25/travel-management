#include "TestRepositoryFileTransport.h"
#include <assert.h>
#include "ValidationException.h"

TestRepositoryFileTransport::TestRepositoryFileTransport()
{
	AirPlane* airPlane = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	Bus* bus = new Bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	this->transportsIn.push_back(airPlane);
	this->transportsIn.push_back(bus);
}

TestRepositoryFileTransport::~TestRepositoryFileTransport()
{
}

void TestRepositoryFileTransport::testAddItem()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	AirPlane* airPlane = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	repositoryFileTransport->addItem(airPlane);
	assert(*repositoryFileTransport->getItem(0) == *airPlane->clone());
}

void TestRepositoryFileTransport::testUpdateItem()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	AirPlane* airPlane1 = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	repositoryFileTransport->addItem(airPlane1);
	AirPlane* airPlane2 = new AirPlane("2923", "Bucuresti", "Madrid", "05.05.2020", 200, 100, 1);
	AirPlane* airPlane3 = new AirPlane("4682", "Cluj", "Paris", "01.08.2020", 260, 200, 1);
	repositoryFileTransport->updateItem(airPlane3, airPlane2);
	assert(*repositoryFileTransport->getItem(0) == *airPlane1);
	repositoryFileTransport->updateItem(airPlane1, airPlane2);
	assert(*repositoryFileTransport->getItem(0) == *airPlane2);
}

void TestRepositoryFileTransport::testDeleteItem()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	AirPlane* airPlane1 = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	repositoryFileTransport->addItem(airPlane1);
	AirPlane* airPlane2 = new AirPlane("2923", "Bucuresti", "Madrid", "05.05.2020", 200, 100, 1);
	repositoryFileTransport->deleteItem(airPlane2);
	assert(repositoryFileTransport->getSize() == 1);
	assert(*repositoryFileTransport->getItem(0) == *airPlane1);
	repositoryFileTransport->deleteItem(airPlane1);
	assert(repositoryFileTransport->getSize() == 0);
}

void TestRepositoryFileTransport::testGetAll()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	AirPlane* airPlane = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	Bus* bus = new Bus("1143", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	repositoryFileTransport->addItem(airPlane);
	repositoryFileTransport->addItem(bus);
	vector<Transport*> transports = repositoryFileTransport->getAll();
	assert(*transports[0] == *airPlane->clone());
	assert(*transports[1] == *bus->clone());
}

void TestRepositoryFileTransport::testGetSize()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	assert(repositoryFileTransport->getSize() == 0);
	repositoryFileTransport->addItem(new Transport());
	assert(repositoryFileTransport->getSize() == 1);
}

void TestRepositoryFileTransport::testGetItem()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	AirPlane* airPlane = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	repositoryFileTransport->addItem(airPlane);
	assert(*repositoryFileTransport->getItem(0) == *airPlane->clone());
	assert(*repositoryFileTransport->getItem(-1) == *(new Transport()));
	assert(*repositoryFileTransport->getItem(1) == *(new Transport()));
}

void TestRepositoryFileTransport::testFindItem()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT();
	AirPlane* airPlane = new AirPlane("2343", "Suceava", "Cluj", "11.11.2020", 40, 36, 1);
	repositoryFileTransport->addItem(airPlane);
	assert(repositoryFileTransport->findItem(airPlane) != -1);
	assert(repositoryFileTransport->findItem(airPlane) == 0);
}

void TestRepositoryFileTransport::testLoadFromFileTXT()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT(this->fileNameInTXT, this->fileNameOutTXT, this->validation);
	repositoryFileTransport->loadFromFile();
	assert(repositoryFileTransport->getSize() == this->transportsIn.size());
	assert(*repositoryFileTransport->getItem(0) == *this->transportsIn[0]);
	assert(*repositoryFileTransport->getItem(1) == *this->transportsIn[1]);
}

void TestRepositoryFileTransport::testLoadFromFileCSV()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV(this->fileNameInCSV, this->fileNameOutCSV, this->validation);
	repositoryFileTransport->loadFromFile();
	assert(repositoryFileTransport->getSize() == this->transportsIn.size());
	assert(*repositoryFileTransport->getItem(0) == *this->transportsIn[0]);
	assert(*repositoryFileTransport->getItem(1) == *this->transportsIn[1]);
}

void TestRepositoryFileTransport::testSavetoFileTXT()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT(this->fileNameInTXT, this->fileNameOutTXT, this->validation);
	repositoryFileTransport->loadFromFile();
	AirPlane* newAirPlane = new AirPlane("4682", "Cluj", "Paris", "01.08.2020", 260, 200, 1);
	repositoryFileTransport->addItem(newAirPlane);
	repositoryFileTransport->saveToFile();
	repositoryFileTransport->setFileName(this->fileNameOutTXT, this->fileNameOutTXT);
	repositoryFileTransport->loadFromFile();
	assert(repositoryFileTransport->getSize() == this->transportsIn.size() + 1);
	vector<Transport*> transports = repositoryFileTransport->getAll();
	for (int i = 0; i < repositoryFileTransport->getSize() - 1; i++)
	{
		assert(*transports[i] == *this->transportsIn[i]);
	}
	assert(*transports[transports.size() - 1] == *newAirPlane);
}

void TestRepositoryFileTransport::testSaveToFileCSV()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV(this->fileNameInCSV, this->fileNameOutCSV, this->validation);
	repositoryFileTransport->loadFromFile();
	AirPlane* newAirPlane = new AirPlane("4682", "Cluj", "Paris", "01.08.2020", 260, 200, 1);
	repositoryFileTransport->addItem(newAirPlane);
	repositoryFileTransport->saveToFile();
	repositoryFileTransport->setFileName(this->fileNameOutCSV, this->fileNameOutCSV);
	repositoryFileTransport->loadFromFile();
	assert(repositoryFileTransport->getSize() == this->transportsIn.size() + 1);
	vector<Transport*> transports = repositoryFileTransport->getAll();
	for (int i = 0; i < repositoryFileTransport->getSize() - 1; i++)
	{
		assert(*transports[i] == *this->transportsIn[i]);
	}
	assert(*transports[transports.size() - 1] == *newAirPlane);
}

void TestRepositoryFileTransport::runTestRepositoryFileTransport()
{
	/*this->testAddItem();
	this->testUpdateItem();
	this->testDeleteItem();
	this->testGetAll();
	this->testGetSize();
	this->testGetItem();
	this->testFindItem();
	this->testLoadFromFileTXT();
	this->testLoadFromFileCSV();
	this->testSavetoFileTXT();
	this->testSaveToFileCSV();*/
}