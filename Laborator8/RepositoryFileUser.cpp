#include "RepositoryFileUser.h"
#include <iterator>
#include <fstream>

RepositoryFileUser::RepositoryFileUser()
{
}

RepositoryFileUser::RepositoryFileUser(string fileNameIn, string fileNameOut)
{
	this->fileNameIn = fileNameIn;
	this->fileNameOut = fileNameOut;
	this->loadFromFile();
}

RepositoryFileUser::~RepositoryFileUser()
{
	this->items.clear();
}

void RepositoryFileUser::setFileName(string fileNameIn, string fileNameOut)
{
	this->fileNameIn = fileNameIn;
	this->fileNameOut = fileNameOut;
}

void RepositoryFileUser::addItem(User& user)
{
	this->items.push_back(user);
	this->saveToFile();
}

void RepositoryFileUser::updateItem(User& oldUser, User& newUser)
{
	for (int i = 0; i < this->items.size(); i++)
	{
		if (this->items[i] == oldUser)
			this->items[i] = newUser;
	}
	this->saveToFile();
}

void RepositoryFileUser::deleteItem(User& user)
{
	for (int i = 0; i < this->items.size(); i++)
	{
		if (this->items[i] == user)
		{
			this->items[i] = this->items[this->items.size() - 1];
			this->items.pop_back();
		}
	}
	this->saveToFile();
}

vector<User> RepositoryFileUser::getAll()
{
	return this->items;
}

int RepositoryFileUser::getSize()
{
	return this->items.size();
}

User RepositoryFileUser::getItem(int position)
{
	if (position >= 0 && position < this->getSize())
	{
		return this->items[position];
	}
	return User();
}

int RepositoryFileUser::findItem(User& user)
{
	for (int i = 0; i < this->items.size(); i++)
	{
		if (this->items[i] == user)
		{
			return i;
		}
	}
	return -1;
}

void RepositoryFileUser::loadFromFile()
{
	ifstream fin(this->fileNameIn);
	if (fin.is_open())
	{
		this->items.clear();
		string line;
		string delimiter = " ";
		int position;
		while (getline(fin, line))
		{
			if (line.substr(0, 10) == "Utilizator")
			{
				line = line.erase(0, 11);

				position = line.find(delimiter);
				string userName = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				string password = line.substr(0, position);

				User user(userName, password);
				this->items.push_back(user);
			}
		}
		fin.close();
	}
}

void RepositoryFileUser::saveToFile()
{
	ofstream fout(this->fileNameOut);
	if (fout.is_open())
	{
		for (User items : this->items)
		{
			fout << items.toString(" ") << endl;
		}
	}
}