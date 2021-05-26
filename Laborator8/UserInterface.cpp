 #include "UserInterface.h"
#include "Transport.h"
#include "AirPlane.h"
#include "Bus.h"
#include "User.h"
#include "ValidationException.h"
#include "Exception.h"
#include <iostream>

UserInterface::UserInterface()
{
	validation = new ValidationTransport();
}

UserInterface::UserInterface(Service* service)
{
	this->service = service;
	this->validation = new ValidationTransport();
}

UserInterface::~UserInterface()
{
}

void UserInterface::setService(Service* service)
{
	this->service = service;
}

void UserInterface::readFileTXT()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileTXT(this->fileNameInTXT, this->fileNameOutTXT, this->validation);
	RepositoryFileUser repositoryFileUser(this->fileNameIn, this->fileNameOut);
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	this->setService(service);
}

void UserInterface::readFileCSV()
{
	RepositoryFileTransport* repositoryFileTransport = new RepositoryFileCSV(this->fileNameOutCSV, this->fileNameOutCSV, this->validation);
	RepositoryFileUser repositoryFileUser(this->fileNameIn, this->fileNameOut);
	Service* service = new Service(repositoryFileTransport, repositoryFileUser);
	this->setService(service);
}

void UserInterface::registration()
{
	string userName;
	cout << " Enter the user name: ";
	getline(cin, userName);
	string password;
	cout << " Enter the password: ";
	cin >> password;
	string confirmPassword;
	cout << " Confirm password: ";
	cin >> confirmPassword;
	if (password == confirmPassword)
	{
		User user(userName, password);
		service->registration(user);
		cout << endl << " The user was added!";
	}
	else
	{
		cout << endl <<" Registration error! ";
	}
}

void UserInterface::login() 
{
	string userName;
	cout << " Enter the user name: ";
	cin >> userName;
	string password;
	cout << " Enter the password: ";
	cin >> password;
	User user(userName, password);
	try
	{
		if (service->login(user) != -1)
		{
			runOperations();
		}
	}
	catch(Exception& exception)
	{
		cout << endl << " Exception: " << exception.getMessage();
	}
}

void UserInterface::logout()
{
	while (true)
	{
		showMenuUsersForLogout();
		int command;
		cout << " Enter your option: ";
		cin >> command;
		cout << endl;
		if (command == 0)
		{
			break;
		}
		if (command == 1)
		{
			login();
			cout << endl;
			break;
		}
		if (command < 0 || command > 1)
		{
			cout << " Impposible command! " << endl;
		}
	}
}

void UserInterface::addAirPlane()
{
	string code, arrivalLocation, deppartureLocation, date;
	int totalNumberOfSeats, numberOfReservedSeats;
	bool layover;
	cout << " Enter the code: ";
	cin >> code;
	cout << " Enter the arrival location: ";
	cin >> arrivalLocation;
	cout << " Enter the depparture location: ";
	cin >> deppartureLocation;
	cout << " Enter the date: ";
	cin >> date;
	cout << " Enter the total number of seats: ";
	cin >> totalNumberOfSeats;
	cout << " Enter the number of reserved seats: ";
	cin >> numberOfReservedSeats;
	cout << " Enter the layover: ";
	cin >> layover;
	AirPlane* airPlane = new AirPlane(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats, layover);
	try
	{
		service->addAirPlane(airPlane);
		cout << endl << " The air plane was added! " << endl;
	}
	catch (Exception & exception)
	{
		cout << endl << "Exception:" << exception.getMessage() << endl;
	}
}

void UserInterface::addBus()
{
	string code, arrivalLocation, deppartureLocation, date;
	int totalNumberOfSeats, numberOfReservedSeats, numberOfTravelDays;
	cout << " Enter the code: ";
	cin >> code;
	cout << " Enter the arrival location: ";
	cin >> arrivalLocation;
	cout << " Enter the depparture location: ";
	cin >> deppartureLocation;
	cout << " Enter the date: ";
	cin >> date;
	cout << " Enter the total number of seats: ";
	cin >> totalNumberOfSeats;
	cout << " Enter the number of reserved seats: ";
	cin >> numberOfReservedSeats;
	cout << " Enter the number of travel days: ";
	cin >> numberOfTravelDays;
	Bus* bus = new Bus(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats, numberOfTravelDays);
	try
	{
		service->addBus(bus);
		cout << endl << " The bus was added! " << endl;
	}
	catch (Exception & exception)
	{
		cout << endl << "Exception:" << exception.getMessage() << endl;
	}
}
void UserInterface::readItem()
{
	while (true)
	{
		showMenuTransports();
		int command;
		cout << endl << " Enter your option: ";
		cin >> command;
		cout << endl;
		if (command == 0)
		{
			break;
		}
		if (command == 1)
		{
			addAirPlane();
			cout << endl;
			break;
		}
		if (command == 2)
		{
			addBus();
			cout << endl;
			break;
		}
		if (command < 0 || command > 2)
		{
			cout << " Impposible command! " << endl;
		}
	}
}

void UserInterface::updateAirPlane()
{
	string code, arrivalLocation = "", deppartureLocation = "", date = "";
	int totalNumberOfSeats = 0, numberOfReservedSeats = 0, numberOfTravelDays = 0;
	bool layover = 0;
	cout << " Enter the code of air plane you want to update: ";
	cin >> code;
	AirPlane* oldAirPlane = new AirPlane(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats, layover);
	cout << endl << " Enter the new transport! " << endl;
	cout << " Enter the code: ";
	cin >> code;
	cout << " Enter the arrival location: ";
	cin >> arrivalLocation;
	cout << " Enter the depparture location: ";
	cin >> deppartureLocation;
	cout << " Enter the date: ";
	cin >> date;
	cout << " Enter the total number of seats: ";
	cin >> totalNumberOfSeats;
	cout << " Enter the number of reserved seats: ";
	cin >> numberOfReservedSeats;
	cout << " Enter the layover: ";
	cin >> layover;
	AirPlane* newAirPlane = new AirPlane(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats, layover);
	try
	{
		service->updateAirPlane(oldAirPlane, newAirPlane);
		cout << endl << " The air plane was updated! " << endl;
	}
	catch (Exception & exception)
	{
		cout << endl << "Exception:" << exception.getMessage() << endl;
	}
}

void UserInterface::updateBus()
{
	string code, arrivalLocation = "", deppartureLocation = "", date = "";
	int totalNumberOfSeats = 0, numberOfReservedSeats = 0, numberOfTravelDays = 0;
	cout << " Enter the code of bus you want to update: ";
	cin >> code;
	Bus* oldBus = new Bus(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats, numberOfTravelDays);
	cout << endl << " Enter the new transport! " << endl;
	cout << " Enter the code: ";
	cin >> code;
	cout << " Enter the arrival location: ";
	cin >> arrivalLocation;
	cout << " Enter the depparture location: ";
	cin >> deppartureLocation;
	cout << " Enter the date: ";
	cin >> date;
	cout << " Enter the total number of seats: ";
	cin >> totalNumberOfSeats;
	cout << " Enter the number of reserved seats: ";
	cin >> numberOfReservedSeats;
	cout << " Enter the number of travel days: ";
	cin >> numberOfTravelDays;
	Bus* newBus = new Bus(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats, numberOfTravelDays);
	try
	{
		service->updateBus(oldBus, newBus);
		cout << endl << " The bus was updated! " << endl;
	}
	catch (Exception & exception)
	{
		cout << endl << "Exception:" << exception.getMessage() << endl;
	}
}

void UserInterface::updateItem()
{
	while (true)
	{
		showMenuTransports();
		int command;
		cout << endl << " Enter your option: ";
		cin >> command;
		cout << endl;
		if (command == 0)
		{
			break;
		}
		if (command == 1)
		{
			updateAirPlane();
			cout << endl;
			break;
		}
		if (command == 2)
		{
			updateBus();
			cout << endl;
			break;
		}
		if (command < 0 || command > 2)
		{
			cout << " Impposible command! " << endl;
		}
	}
}

void UserInterface::deleteItem()
{
	string code, arrivalLocation = "", deppartureLocation = "", date = "";
	int totalNumberOfSeats = 0, numberOfReservedSeats = 0;
	cout << " Enter the code of transport you want to delete: ";
	cin >> code;
	Transport* transport = new Transport(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats);
	try
	{
		service->deleteTransport(transport);
		cout << endl << " The transport was deleted! " << endl;
	}
	catch (Exception& exception)
	{
		cout << endl << " Exception: " << exception.getMessage();
	}
}

void UserInterface::showAll()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	vector<Transport*> transports = service->getAllTransport();
	for(Transport* transport : transports)
	{
		if (transport->getTotalNumberOfSeats() == transport->getNumberOfReservedSeats())
		{
			SetConsoleTextAttribute(handle, 12);
			cout << transport->toString(" ") << endl;
			SetConsoleTextAttribute(handle, 15);
		}
		else
			cout << transport->toString(" ") << endl;
	}
}

void UserInterface::search()
{
	string date;
	cout << " Insert the date you want to search: ";
	cin >> date;
	Transport* filterTransportByDate[100];
	int length = 0, i;
	service->search(date, filterTransportByDate, length);
	for (i = 0; i < length; i++)
	{
		cout << filterTransportByDate[i]->toString(" ") << endl;
	}
}

void UserInterface::reservation()
{
	string code;
	cout << " Insert the code you want to reserve seats: ";
	cin >> code;
	int numberOfReservedSeats;
	cout << " Insert the number of reserved seats: ";
	cin >> numberOfReservedSeats;
	try
	{
		service->reservation(code, numberOfReservedSeats);
		cout << endl << " The seats are reserved! " << endl;
	}
	catch (Exception & exception)
	{
		cout << endl << " Exception: " << exception.getMessage() << endl;
	}
}

void UserInterface::showMenuFiles()
{
	cout << endl;
	cout << " 0. Exit " << endl;
	cout << " 1. File TXT " << endl;
	cout << " 2. File CSV " << endl;
	cout << endl;
}

void UserInterface::showMenuUsersForLogin()
{
	cout << endl;
	cout << " 0. Exit " << endl;
	cout << " 1. Registration " << endl;
	cout << " 2. Login " << endl;
	cout << " 3. Logout " << endl;
	cout << endl;
}

void UserInterface::showMenuUsersForLogout()
{
	cout << endl;
	cout << " 0. Exit " << endl;
	cout << " 1. Login " << endl;
	cout << endl;
}
void UserInterface::showMenuTransports()
{
	cout << endl;
	cout << " 0. Exit " << endl;
	cout << " 1. Air Plane " << endl;
	cout << " 2. Bus " << endl;
	cout << endl;
}

void UserInterface::showMenuOperations()
{
	cout << endl;
	cout << " 0. Exit " << endl;
	cout << " 1. Add " << endl;
	cout << " 2. Show all " << endl;
	cout << " 3. Update " << endl;
	cout << " 4. Delete " << endl;
	cout << " 5. Search " << endl;
	cout << " 6. Reservation " << endl;
	cout << endl;
}

void UserInterface::runFiles()
{
	while (true)
	{
		showMenuFiles();
		int command;
		cout << " Enter your option: ";
		cin >> command;
		cout << endl;
		if (command == 0)
		{
			break;
		}
		if (command == 1)
		{
			readFileTXT();
			cout << endl;
			break;
		}
		if (command == 2)
		{
			readFileCSV();
			cout << endl;
			break;
		}
		if (command < 0 || command > 2)
		{
			cout << " Impposible command! " << endl;
		}
	}
}

void UserInterface::runUsers()
{
	while (true)
	{
		showMenuUsersForLogin();
		int command;
		cout << " Enter your option: ";
		cin >> command;
		cout << endl;
		if (command == 0)
		{
			break;
		}
		if (command == 1)
		{
			registration();
			cout << endl;
		}
		if (command == 2)
		{
			login();
			cout << endl;
			break;
		}
		if (command == 3)
		{
			logout();
			cout << endl;
			break;
		}
		if (command < 0 || command > 3)
		{
			cout << " Impposible command! " << endl;
		}
	}
}

void UserInterface::runOperations()
{
	while (true)
	{
		showMenuOperations();
		int command;
		cout << " Enter your option: ";
		cin >> command;
		cout << endl;
		if (command == 0)
		{
			runUsers();
			break;
		}
		if (command == 1)
		{
			readItem();
			cout << endl;
		}
		if (command == 2)
		{
			showAll();
			cout << endl;
		}
		if (command == 3)
		{
			updateItem();
			cout << endl;
		}
		if (command == 4)
		{
			deleteItem();
			cout << endl;
		}
		if (command == 5)
		{
			search();
			cout << endl;
		}
		if (command == 6)
		{
			reservation();
			cout << endl;
		}
		if (command < 0 || command > 6)
		{
			cout << " Impposible command! " << endl;
		}
	}
}
void UserInterface::runUserInterface()
{
	runFiles();
	runUsers();
}