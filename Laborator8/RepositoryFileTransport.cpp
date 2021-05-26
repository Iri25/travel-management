#include "RepositoryFileTransport.h"
#include "ValidationException.h"
#include "ValidationAirPlane.h"
#include "ValidationBus.h"
#include <iostream>

RepositoryFileTransport::RepositoryFileTransport()
{
	this->validation = new ValidationTransport();
}

RepositoryFileTransport::RepositoryFileTransport(string fileNameIn, string fileNameOut, ValidationTransport* validation)
{
	this->fileNameIn = fileNameIn;
	this->fileNameOut = fileNameOut;
	this->validation = validation;
}

RepositoryFileTransport::~RepositoryFileTransport()
{
}

void RepositoryFileTransport::setFileName(string fileNameIn, string fileNameOut)
{
	this->fileNameIn = fileNameIn;
	this->fileNameOut = fileNameOut;
}

void RepositoryFileTransport::addItem(Transport* transport)
{
	this->items.push_back(transport->clone());
	this->saveToFile();
}

void RepositoryFileTransport::updateItem(Transport* oldTransport, Transport* newTransport)
{

	for (int i = 0; i < this->items.size(); i++)
	{
		if (*(this->getItem(i)) == *oldTransport)
		{
			delete this->items[i];
			this->items[i] = newTransport->clone();
			this->saveToFile();
			return;
		}
	}
}

void RepositoryFileTransport::deleteItem(Transport* transport)
{
	for (int i = 0; i < this->items.size(); i++)
	{
		if (**(this->items.begin() + i) == *transport)
		{
			delete this->items[i];
			this->items.erase(this->items.begin() + i);
			this->saveToFile();
			return;
		}
	}
}

vector<Transport*> RepositoryFileTransport::getAll()
{
	return this->items;
}

int RepositoryFileTransport::getSize()
{
	return this->items.size();
}

Transport* RepositoryFileTransport::getItem(int position)
{
	if (position >= 0 && position < this->getSize())
	{
		return this->items[position]->clone();
	}
	return new Transport();
}

int RepositoryFileTransport::findItem(Transport* transport)
{
	for (int i = 0; i < this->items.size(); i++)
	{
		if (**(this->items.begin() + i) == *transport)
			return i;
		
	}
	return -1;
}

void RepositoryFileTransport::emptyRepository()
{
	for (int i = 0; i < this->getSize(); i++)
	{
		delete this->items[i];
	}
	this->items.clear();
}