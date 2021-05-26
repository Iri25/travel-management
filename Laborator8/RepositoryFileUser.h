#pragma once
#ifndef REPOSITORY_FILE_USER_H
#define REPOSITORY_FILE_USER_H
#include "User.h"
#include <vector>
#include <string>

using namespace std;

class RepositoryFileUser
{
private:
    vector<User> items;
    string fileNameIn;
    string fileNameOut;
public:
    RepositoryFileUser();
    RepositoryFileUser(string fileNameIn, string fileNameOut);
    ~RepositoryFileUser();

    void setFileName(string fileNameIn, string fileNameOut);

    void addItem(User& user);
    void updateItem(User& oldUser, User& newUser);
    void deleteItem(User& user);

    vector<User> getAll();
    int getSize();

    User getItem(int position);
    int findItem(User& user);

    void loadFromFile();
    void saveToFile();
};

#endif