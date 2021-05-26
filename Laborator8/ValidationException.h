#pragma once
#ifndef VALIDATION_EXCEPTION
#define VALIDATION_EXCEPTION_H
#include <exception>
#include <string>

using namespace std;

class ValidationException : public exception
{
private:
    string message;
public:
    ValidationException();
    ValidationException(string message);
    ~ValidationException();

    virtual string what() throw();
};

#endif 