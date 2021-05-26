#pragma once
#ifndef TEST_SERVICE_H
#define TEST_SERVICE_H
#include "Service.h"

class TestService
{
private:
	Service* service;

	ValidationTransport* validation;

	const string fileNameInTXT = "TestTransportsIn.txt";
	const string fileNameOutTXT = "TestTransportsOut.txt";
	const string fileNameInCSV = "TestTransportsIn.csv";
	const string fileNameOutCSV = "TestTransportsOut.csv";
	const string fileNameIn = "TestUsersIn.txt";
	const string fileNameOut = "TestUsersOut.txt";

	vector<Transport*> transportsIn;

    void testAddTransport();
    void testUpdateTransport();
    void testDeleteTransport();

    void testGetAllTransport();
    void testGetSizeTransport();

    void testGetTransport();
    void testFindTransport();

	void testAddUser();
	void testUpdateUser();
	void testDeleteUser();

	void testGetAllUser();
	void testGetSizeUser();

	void testGetUser();
	void testFindUser();

	void testRegistration();
	void testLogin();

	void testSearch();
	void testBuy();
public:
	TestService();
	~TestService();

	void runTestService();
};
#endif