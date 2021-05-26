#pragma once
#ifndef TEST_REPOSITORY_FILE_TRANSPORT_H
#define TEST_REPOSITORY_FILE_TRANSPORT_H
#include "AirPlane.h"
#include "Bus.h"
#include "RepositoryFileTransport.h"
#include "RepositoryFileTXT.h"
#include "RepositoryFileCSV.h"

class TestRepositoryFileTransport
{
private:
    RepositoryFileTransport* repositoryFileTransport;
    ValidationTransport* validation;

    const string fileNameInTXT = "TestTransportsIn.txt";
    const string fileNameOutTXT = "TestTransportsOut.txt";
    const string fileNameInCSV = "TestTransportsIn.csv";
    const string fileNameOutCSV = "TestTransportsOut.csv";

    vector<Transport*> transportsIn;

    void testAddItem();
    void testUpdateItem();
    void testDeleteItem();

    void testGetAll();
    void testGetSize();

    void testGetItem();
    void testFindItem();

    void testLoadFromFileTXT();
    void testLoadFromFileCSV();

    void testSavetoFileTXT();
    void testSaveToFileCSV();
public:
    TestRepositoryFileTransport();
    ~TestRepositoryFileTransport();

    void runTestRepositoryFileTransport();
};

#endif 