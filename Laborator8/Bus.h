#pragma once
#ifndef DOMAIN_DERIVED_2_H
#define DOMAIN_DERIVED_2_H
#include "Transport.h"

class Bus : public Transport
{
private:
    int numberOfTravelDays;
public:
    Bus();
    Bus(string code, string arrivalLocation, string deppartureLocation, string date, int totalNumberOfSeats, int numberOfReservedSeats, int numberOfTravelDays);
    Bus(const Bus& transport);
    ~Bus();

    Transport* clone();

    Bus& operator = (const Bus& airPlane);
    bool operator == (const Bus& airPlane);

    int getNumberOfTravelDays();

    void setNumberOfTravelDays(int numberOfTravelDays);

    string toString(string delimiter);
};

#endif 