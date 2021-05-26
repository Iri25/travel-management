#pragma once
#ifndef DELETE_1_H
#define DELETE_1_H
#include "DeleteException2.h"
#include <string>
#include <exception>

using namespace std;

class DeleteException1 : public DeleteException2
{
protected:
    string message;
public:
    DeleteException1(string message);

    string getMessage();
};

#endif;