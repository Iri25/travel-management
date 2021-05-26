#pragma once
#ifndef VALIDATION_TRANSPORT_H
#define VALIDATION_TRANSPORT_H
#include "Transport.h"
#include <exception>
#include <string>

using namespace std;

class ValidationTransport
{
protected:
    int errors;
    string message;
public:
    ValidationTransport();
    ~ValidationTransport();

    virtual int validate(Transport* transport);

    string toString();
};

#endif