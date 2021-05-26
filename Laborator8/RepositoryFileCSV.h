#pragma once
#ifndef REPOSITORY_FILE_CSV_H
#define REPOSITORY_FILE_CSV_ H
#include "RepositoryFileTransport.h"

class RepositoryFileCSV : public RepositoryFileTransport
{
public:
	RepositoryFileCSV();
	RepositoryFileCSV(string fileNameIn, string fileNameOut, ValidationTransport* validation);
	~RepositoryFileCSV();

	void loadFromFile();
	void saveToFile();
};

#endif