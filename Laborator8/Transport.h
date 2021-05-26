#pragma once
#ifndef DOMAIN_BASE_H
#define DOMAIN_BASE_H
#include <string>

using namespace std;

class Transport
{
protected:
    string code;
    string arrivalLocation;
    string deppartureLocation;
    string date;
    int totalNumberOfSeats;
    int numberOfReservedSeats;
public:
    Transport();
    Transport(string code, string arrivalLocation, string deppartureLocation, string date, int totalNumberOfSeats, int numberOfReservedSeats);
    Transport(const Transport& transport);
    ~Transport();

    virtual Transport* clone();

    Transport& operator = (const Transport& transport);
    bool operator == (const Transport& transport);

    string getCode();
    string getArrivalLocation();
    string getDeppartureLocation();
    string getDate();
    int getTotalNumberOfSeats();
    int getNumberOfReservedSeats();

    void setCode(string code);
    void setArrivalLocation(string arrivalLocation);
    void setDeppartureLocation(string deppartureLocation);
    void setDate(string date);
    void setTotalNumberOfSeats(int totalNumberOfSeats);
    void setNumberOfReservedSeats(int numberOfReservedSeats);

    virtual string toString(string delimiter);
};

#endif 