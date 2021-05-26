#pragma once
#ifndef TEST_REPOSITORY_FILE_USER_H
#define TEST_REPOSITORY_FILE_USER_H
#include "User.h"
#include "RepositoryFileUser.h"

class TestRepositoryFileUser
{
private:
    RepositoryFileUser repositoryFileUser;

    const string fileNameInTXT = "TestUsersIn.txt";
    const string fileNameOutTXT = "TestUsersOut.txt";

    vector<User> usersIn;

    void testAddItem();
    void testUpdateItem();
    void testDeleteItem();

    void testGetAll();
    void testGetSize();

    void testGetItem();
    void testFindItem();

    void testLoadFromFileTXT();

    void testSavetoFileTXT();
public:
    TestRepositoryFileUser();
    ~TestRepositoryFileUser();

    void runTestRepositoryFileUser();
};

#endif