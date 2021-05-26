#include "User.h"

User::User()
{
}

User::User(string userName, string password)
{
	this->userName = userName;
	this->password = password;
}

User::User(const User& user)
{
	this->userName = user.userName;
	this->password = user.password;
}

User::~User()
{
}

User& User::operator=(const User& user)
{
	if (this == &user)
		return *this;
	this->userName = user.userName;
	this->password = user.password;
	return *this;
}

bool User::operator==(const User& user)
{
	return (userName == user.userName);
}

string User::getUserName()
{
	return this->userName;
}

string User::getPassword()
{
	return this->password;
}

void User::setUserName(string userName)
{
	this->userName = userName;
}

void User::setPassword(string password)
{
	this->password = password;
}

string User::toString(string delimiter)
{
	return "Utilizator" + delimiter + this->userName + delimiter + this->password;
}