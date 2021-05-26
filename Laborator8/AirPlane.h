#pragma once
#ifndef DOMAIN_DERIVED_1_H
#define DOMAIN_DERIVED_1_H
#include "Transport.h"

class AirPlane : public Transport
{
private:
    bool layover;
public:
    AirPlane();
    AirPlane(string code, string arrivalLocation, string deppartureLocation, string date, int totalNumberOfSeats, int numberOfReservedSeats, bool layover);
    AirPlane(const AirPlane& transport);
    ~AirPlane();

    Transport* clone();

    AirPlane& operator = (const AirPlane& airPlane);
    bool operator == (const AirPlane& airPlane);

    bool getLayover();

    void setLayover(bool layover);

    string toString(string delimiter);
};

#endif 