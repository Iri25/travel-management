#pragma once
#ifndef VALIDATION_BUS_H
#define VALIDATION_BUS_H
#include "Bus.h"
#include "ValidationTransport.h"

class ValidationBus : public ValidationTransport
{
private:
    int errors;
    string message;
public:
    ValidationBus();
    ~ValidationBus();

    int validate(Transport* transport);
};

#endif