#pragma once
#ifndef DELETE_2_H
#define DELETE_2_H
#include "Transport.h"
#include <string>
#include <exception>

using namespace std;

class DeleteException2 : public exception
{
protected:
    string message;
public:
    DeleteException2(string message);

    string getMessage();
};

#endif;