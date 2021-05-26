#pragma once
#include <ostream>

using namespace std;

class User 
{
private:
    string userName;
    string password;
public:
    User();
    User(string userName, string password);
    User(const User& user);
    ~User();

    User& operator = (const User& user);
    bool operator == (const User& user);

    string getUserName();
    string getPassword();

    void setUserName(string userName);
    void setPassword(string password);

    string toString(string delimiter);
};