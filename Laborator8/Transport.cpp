#include "Transport.h"
#include <string>

Transport::Transport()
{
	this->totalNumberOfSeats = 0;
	this->numberOfReservedSeats = 0;
}

Transport::Transport(string code, string arrivalLocation, string deppartureLocation, string date, int totalNumberOfSeats, int numberOfReservedSeats)
{
	this->code = code;
	this->arrivalLocation = arrivalLocation;
	this->deppartureLocation = deppartureLocation;
	this->date = date;
	this->totalNumberOfSeats = totalNumberOfSeats;
	this->numberOfReservedSeats = numberOfReservedSeats;
}

Transport::Transport(const Transport& transport)
{
	this->code = transport.code;
	this->arrivalLocation = transport.arrivalLocation;
	this->deppartureLocation = transport.deppartureLocation;
	this->date = transport.date;
	this->totalNumberOfSeats = transport.totalNumberOfSeats;
	this->numberOfReservedSeats = transport.numberOfReservedSeats;
}

Transport::~Transport()
{
}

Transport* Transport::clone()
{
	return new Transport(this->code, this->arrivalLocation, this->deppartureLocation, this->date, this->totalNumberOfSeats, this->numberOfReservedSeats);
}

Transport& Transport::operator=(const Transport& transport)
{
	this->code = transport.code;
	this->arrivalLocation = transport.arrivalLocation;
	this->deppartureLocation = transport.deppartureLocation;
	this->date = transport.date;
	this->totalNumberOfSeats = transport.totalNumberOfSeats;
	this->numberOfReservedSeats = transport.numberOfReservedSeats;
	return *this;
}

bool Transport::operator==(const Transport& transport)
{
	return (code == transport.code);
}

string Transport::getCode()
{
	return this->code;
}

string Transport::getArrivalLocation()
{
	return this->arrivalLocation;
}

string Transport::getDeppartureLocation()
{
	return this->deppartureLocation;
}

string Transport::getDate()
{
	return this->date;
}

int Transport::getTotalNumberOfSeats()
{
	return this->totalNumberOfSeats;
}

int Transport::getNumberOfReservedSeats()
{
	return this->numberOfReservedSeats;
}

void Transport::setCode(string code)
{
	this->code = code;
}

void Transport::setArrivalLocation(string arrivalLocation)
{
	this->arrivalLocation = arrivalLocation;
}

void Transport::setDeppartureLocation(string deppartureLocation)
{
	this->deppartureLocation = deppartureLocation;
}

void Transport::setDate(string date)
{
	this->date = date;
}

void Transport::setTotalNumberOfSeats(int totalNumberOfSeats)
{
	this->totalNumberOfSeats = totalNumberOfSeats;
}

void Transport::setNumberOfReservedSeats(int numberOfReservedSeats)
{
	this->numberOfReservedSeats = numberOfReservedSeats;
}

string Transport::toString(string delimiter)
{
	return this->code + delimiter + this->arrivalLocation + delimiter + this->deppartureLocation + delimiter + this->date + delimiter + to_string(this->totalNumberOfSeats) + delimiter + to_string(this->numberOfReservedSeats);
}