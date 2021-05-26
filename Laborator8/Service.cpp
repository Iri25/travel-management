#include "Service.h"
#include "Exception.h"
#include "ValidationException.h"
#include "ValidationAirPlane.h"
#include "ValidationBus.h"
#include "DeleteException1.h"
#include "DeleteException2.h"
#include <string>
#include <iostream>

Service::Service(ValidationTransport* validation)
{
	this->validation = validation;
}

Service::Service(RepositoryFileTransport* repositoryFileTransport, RepositoryFileUser repositoryFileUser)
{
	this->repositoryFileTransport = repositoryFileTransport;
	this->repositoryFileUser = repositoryFileUser;
}

Service::~Service()
{
}

void Service::setRepository(RepositoryFileTransport* repositoryFileTransport, RepositoryFileUser repositoryFileUser)
{
	this->repositoryFileTransport = repositoryFileTransport;
	this->repositoryFileUser = repositoryFileUser;
}

void Service::addAirPlane(AirPlane* airPlane)
{
	this->validation = new ValidationAirPlane();
	try
	{
		if ((((ValidationAirPlane*)validation)->validate(airPlane) == 0))
		{
			this->validation = ((ValidationAirPlane*)validation);
			Transport* transport = (Transport*)airPlane;
			repositoryFileTransport->addItem(transport);
		}
		else
		{
			throw ValidationException(this->validation->toString());
		}
	}
	catch (ValidationException& exception)
	{
		throw Exception(" Add error! " + exception.what());
	}
}

void Service::addBus(Bus* bus)
{
	this->validation = new ValidationBus();
	try
	{
		if ((((ValidationBus*)validation)->validate(bus) == 0))
		{
			this->validation = ((ValidationBus*)validation);
			Transport* transport = (Transport*)bus;
			repositoryFileTransport->addItem(transport);
		}
		else
		{
			throw ValidationException(this->validation->toString());
		}
	}
	catch (ValidationException& exception)
	{
		throw Exception(" Add error! " + exception.what());
	}
}

void Service::updateAirPlane(AirPlane* oldAirPlane, AirPlane* newAirPlane)
{
	this->validation = new ValidationAirPlane();
	try
	{
		if (findTransport(oldAirPlane) != -1)
		{
			if (findTransport(newAirPlane) == -1)
			{
				if ((((ValidationAirPlane*)validation)->validate(newAirPlane) == 0))
				{
					this->validation = ((ValidationAirPlane*)validation);
					Transport* transport = (Transport*)newAirPlane;
					repositoryFileTransport->updateItem(oldAirPlane, newAirPlane);
				}
				else
				{
					throw ValidationException(this->validation->toString());
				}
			}
			else
			{
				throw Exception(" The code of the new air plane exist! ");
			}
		}
		else
		{
			throw Exception(" The code of the old air plane doesn't exist! ");
		}
	}
	catch (ValidationException & exception)
	{
		throw Exception(" Update error! " + exception.what());
	}
}

void Service::updateBus(Bus* oldBus, Bus* newBus)
{
	this->validation = new ValidationBus();
	try
	{
		if (findTransport(oldBus) != -1)
		{
			if (findTransport(newBus) == -1)
			{
				if ((((ValidationBus*)validation)->validate(newBus) == 0))
				{
					this->validation = ((ValidationBus*)validation);
					Transport* transport = (Transport*)newBus;
					repositoryFileTransport->updateItem(oldBus, newBus);
				}
				else
				{
					throw ValidationException(this->validation->toString());
				}
			}
			else
			{
				throw Exception(" The code of the new bus exist! ");
			}
		}
		else
		{
			throw Exception(" The code of the old bus doesn't exist! ");
		}
	}
	catch (ValidationException& exception)
	{
		throw Exception(" Update error! " + exception.what());
	}
}
void Service::deleteTransport(Transport* transport)
{
	
	if (repositoryFileTransport->findItem(transport) != -1)
	{
			repositoryFileTransport->deleteItem(transport);
	}
}

vector<Transport*> Service::getAllTransport()
{
	return repositoryFileTransport->getAll();
}

int Service::getSizeTransport()
{
	return repositoryFileTransport->getSize();
}

Transport* Service::getTransport(int position)
{
	return repositoryFileTransport->getItem(position);
}

int Service::findTransport(Transport* transport)
{
	return repositoryFileTransport->findItem(transport);
}

void Service::addUser(User& user)
{
	repositoryFileUser.addItem(user);
}

void Service::updateUser(User& oldUser, User& newUser)
{
	repositoryFileUser.updateItem(oldUser, newUser);
}

void Service::deleteUser(User& user)
{
	if (repositoryFileUser.findItem(user) != -1)
	{
		repositoryFileUser.deleteItem(user);
	}
	else
	{
		throw Exception(" Deletion error! ");
	}
}

vector<User> Service::getAllUser()
{
	return repositoryFileUser.getAll();
}

int Service::getSizeUser()
{
	return repositoryFileUser.getSize();
}

User Service::getUser(int position)
{
	return repositoryFileUser.getItem(position);
}

int Service::findUser(User& user)
{
	return repositoryFileUser.findItem(user);
}

void Service::registration(User& user)
{
	repositoryFileUser.addItem(user);
}

int Service::login(User& user)
{
	int position = repositoryFileUser.findItem(user);
	if (position != -1)
		return position;
	else
		throw Exception(" Login error! ");
}

void Service::search(string date, Transport* filterTransportsByDate[], int& length)
{
	for (int i = 0; i < this->getSizeTransport(); i++)
	{
		Transport* currentTransport = this->getTransport(i);
		if (currentTransport->getDate() == date)
		{
			filterTransportsByDate[length++] = currentTransport;
		}
	}
}

void Service::reservation(string code, int numberOfReservedSeats)
{
	bool ok = 0;
	for (int i = 0; i < this->getSizeTransport(); i++)
	{
		Transport* currentTransport = this->getTransport(i);
		if (currentTransport->getCode() == code)
		{
			ok = 1;
			int numberOfSeatsAvailable = currentTransport->getTotalNumberOfSeats() - currentTransport->getNumberOfReservedSeats();
			if (numberOfReservedSeats >= 0)
			{
				if (numberOfSeatsAvailable >= numberOfReservedSeats)
				{
					currentTransport->setNumberOfReservedSeats(currentTransport->getNumberOfReservedSeats() + numberOfReservedSeats);
					Transport* newTransport = currentTransport;
					repositoryFileTransport->updateItem(currentTransport, newTransport);
				}
				else
				{
					throw Exception(" Buy error! ");
				}
			}
			else
			{
				throw Exception(" The number of reserved seats must be positive! ");
			}
		}
	}
	if(ok == 0)
		throw Exception(" Code error! ");
}

void Service::deleteTransport1(string code, string deppartureLocation)
{
	string arrivalLocation = "", date = "";
	int totalNumberOfSeats = 0, numberOfReservedSeats = 0;
	Transport* transport = new Transport(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats);
	bool ok = 0;
	for (int i = 0; i < this->getSizeTransport(); i++)
	{
		Transport* currentTransport = this->getTransport(i);
		if (currentTransport->getCode() == code)
		{
			ok = 1;
			if (currentTransport->getDeppartureLocation() == deppartureLocation)
			{
				repositoryFileTransport->deleteItem(transport);
			}
			else
			{
				throw DeleteException1(" Delete error! ");
			}
		}
	}
	if (ok == 0)
	{
		throw DeleteException2(" Code error! ");
	}
}

void Service::deleteTransport2(Transport* transport)
{
	int n = this->getSizeTransport();
	int m = this->getSizeTransport();
	for (int i = 0; i < n; i++)
	{
		if (*getTransport(i) == *transport)
		{
			for (int j = 0; j < m; j++)
			{
				if (getTransport(j)->getDate() == transport->getDate())
				{
					if (getTransport(j)->getArrivalLocation() == transport->getDeppartureLocation())
					{
						deleteTransport(getTransport(j));
					}
					if (getTransport(j)->getDeppartureLocation() == transport->getArrivalLocation())
					{
						deleteTransport(getTransport(j));
					}
					deleteTransport(transport);
				}

			}
		}
	}
}

void Service::emptyService()
{
	repositoryFileTransport->emptyRepository();

}