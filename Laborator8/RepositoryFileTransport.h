#pragma once
#ifndef REPOSITORY_FILE_TRANSPORT_H
#define REPOSITORY_FILE_TRANSPORT_H
#include "Transport.h"
#include "ValidationTransport.h"
#include <vector>
#include <string>

using namespace std;

class RepositoryFileTransport
{
protected:
    vector<Transport*> items;
    string fileNameIn;
    string fileNameOut;
    ValidationTransport* validation;
public:
    RepositoryFileTransport();
    RepositoryFileTransport(string fileNameIn, string fileNameOut, ValidationTransport* validation);
    ~RepositoryFileTransport();

    void setFileName(string fileNameIn, string fileNameOut);

    void addItem(Transport* transport);
    void updateItem(Transport* oldTransport, Transport* newTransport);
    void deleteItem(Transport* Transport);

    vector<Transport*> getAll();
    int getSize();

    Transport* getItem(int position);
    int findItem(Transport* transport);
    
    void emptyRepository();

    virtual void loadFromFile() = 0;
    virtual void saveToFile() = 0;
};

#endif