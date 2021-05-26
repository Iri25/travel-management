#include "Bus.h"
#include <string>

Bus::Bus() : Transport()
{
	this->numberOfTravelDays = 0;
}

Bus::Bus(string code, string arrivalLocation, string deppartureLocation, string date, int totalNumberOfSeats, int numberOfReservedSeats, int numberOfTravelDays) : Transport(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats)
{
	this->numberOfTravelDays = numberOfTravelDays;
}

Bus::Bus(const Bus& bus) : Transport(bus)
{
	this->numberOfTravelDays = bus.numberOfTravelDays;
}

Bus::~Bus()
{
}

Transport* Bus::clone()
{
	return new Bus(this->code, this->arrivalLocation, this->deppartureLocation, this->date, this->totalNumberOfSeats, this->numberOfReservedSeats, this->numberOfTravelDays);
}

Bus& Bus::operator=(const Bus& bus)
{
	Transport::operator=(bus);
	this->numberOfTravelDays = bus.numberOfTravelDays;
	return *this;
}

bool Bus::operator==(const Bus& bus)
{
	return this->Transport::operator==(bus);
}

int Bus::getNumberOfTravelDays()
{
	return this->numberOfTravelDays;
}

void Bus::setNumberOfTravelDays(int numberOfTravelDays)
{
	this->numberOfTravelDays = numberOfTravelDays;
}

string Bus::toString(string delimiter)
{
	return "Autobuz" + delimiter + Transport::toString(delimiter) + delimiter + to_string(numberOfTravelDays);
}