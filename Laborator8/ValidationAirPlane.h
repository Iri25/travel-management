#pragma once
#ifndef VALIDATION_AIR_PLANE_H
#define VALIDATION_AIR_PLANE_H
#include "AirPlane.h"
#include "ValidationTransport.h"

class ValidationAirPlane : public ValidationTransport
{
private:
    int errors;
    string message;
public:
    ValidationAirPlane();
    ~ValidationAirPlane();

    int validate(Transport* transport);
};

#endif