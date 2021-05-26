#pragma once
#ifndef REPOSITORY_FILE_TXT_H
#define REPOSITORY_FILE_TXT_H
#include "RepositoryFileTransport.h"

class RepositoryFileTXT : public RepositoryFileTransport
{
public:
	RepositoryFileTXT();
	RepositoryFileTXT(string fileNameIn, string fileNameOut, ValidationTransport* validation);
	~RepositoryFileTXT();

	void loadFromFile();
	void saveToFile();
};

#endif