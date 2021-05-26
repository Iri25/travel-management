#pragma once
#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <exception>

using namespace std;

class Exception : public exception
{
private:
    string message;
public:
    Exception(string message);

    string getMessage();
};

#endif