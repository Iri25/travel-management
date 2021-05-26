#pragma once
#ifndef SERVICE_H
#define SERVICE_H
#include "Transport.h"
#include "AirPlane.h"
#include "Bus.h"
#include "RepositoryFileTransport.h"
#include "RepositoryFileCSV.h"
#include "RepositoryFileTXT.h"
#include "User.h"
#include "RepositoryFileUser.h"
#include "ValidationTransport.h"

class Service
{
private:
	RepositoryFileTransport* repositoryFileTransport;
	RepositoryFileUser repositoryFileUser;
	ValidationTransport* validation;
public:
	Service(ValidationTransport* validation);
	Service(RepositoryFileTransport* repositoryFileTransport, RepositoryFileUser repositoryFileUser);
	~Service();

	void setRepository(RepositoryFileTransport* repositoryFileTransport, RepositoryFileUser repositoryFileUser);

	void addAirPlane(AirPlane* airPlane);
	void addBus(Bus* bus);
	void updateAirPlane(AirPlane* oldAirPlane, AirPlane* newAirPlane);
	void updateBus(Bus* oldBus, Bus* newBus);
	void deleteTransport(Transport* transport);
	vector<Transport*> getAllTransport();
	int getSizeTransport();
	Transport* getTransport(int position);
	int findTransport(Transport* transport);

	void addUser(User& user);
	void updateUser(User& oldUser, User& newUser);
	void deleteUser(User& user);
	vector<User> getAllUser();
	int getSizeUser();
	User getUser(int position);
	int findUser(User& user);

	void registration(User& user);
	int login(User& user);

	void search(string date, Transport* filterTransportsByDate[], int& lenght);
	void reservation(string code, int numberOfReservedSeats);

	void deleteTransport1(string code, string deppartureLocation);
	void deleteTransport2(Transport* transport);

	void emptyService();
};
#endif