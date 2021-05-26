#include "RepositoryFileTXT.h"
#include "AirPlane.h"
#include "Bus.h"
#include <fstream>

RepositoryFileTXT::RepositoryFileTXT() : RepositoryFileTransport()
{
}

RepositoryFileTXT::RepositoryFileTXT(string fileNameIn, string fileNameOut, ValidationTransport* validation) : RepositoryFileTransport(fileNameIn, fileNameOut, validation)
{
	this->loadFromFile();
}

RepositoryFileTXT::~RepositoryFileTXT()
{
}

void RepositoryFileTXT::loadFromFile()
{
	ifstream fin(this->fileNameIn);
	if (fin.is_open())
	{
		this->emptyRepository();
		string line;
		string delimiter = " ";
		int position;
		while (getline(fin, line))
		{
			if (line.substr(0, 5) == "Avion")
			{
				line = line.erase(0, 6);

				position = line.find(delimiter);
				string code = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				string arrivalLocation = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				string deppartureLocation = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				string date = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int totalNumberOfSeats = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int numberOfReservedSeats = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				bool layover = stod(line.substr(0, position));

				AirPlane* airPlane = new AirPlane(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats, layover);
				this->items.push_back(airPlane);
			}
			else if (line.substr(0, 7) == "Autobuz")
			{
				line = line.erase(0, 8);

				position = line.find(delimiter);
				string code = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				string arrivalLocation = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				string deppartureLocation = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				string date = line.substr(0, position);
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int totalNumberOfSeats = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int numberOfReservedSeats = stod(line.substr(0, position));
				line = line.erase(0, position + 1);

				position = line.find(delimiter);
				int numberOfTravelDays = stod(line.substr(0, position));

				Bus* bus = new Bus(code, arrivalLocation, deppartureLocation, date, totalNumberOfSeats, numberOfReservedSeats, numberOfTravelDays);
				this->items.push_back(bus);
			}
		}
		fin.close();
	}
}

void RepositoryFileTXT::saveToFile()
{
	ofstream fout(this->fileNameOut);
	if (fout.is_open())
	{
		for (Transport* items : this->items)
		{
			fout << items->toString(" ") << endl;
		}
	}
}