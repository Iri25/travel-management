#include <iostream>
#include "UserInterface.h"
#include "TestTransport.h"
#include "TestAirPlane.h"
#include "TestBus.h"
#include "TestUser.h"
#include "TestRepositoryFileTransport.h"
#include "TestRepositoryFileUser.h"
#include "TestService.h"
#include "TestException.h"
#include "TestValidationTransport.h"
#include "TestValidationAirPlane.h"
#include "TestValidationBus.h"
#include "Tests.h"

using namespace std;

int main()
{
	
	TestTransport testTransport;
	testTransport.runTestTransport();

	TestAirPlane testAirPlane;
	testAirPlane.runTestAirPlane();

	TestBus testBus;
	testBus.runTestBus();

	TestUser testUser;
	testUser.runTestUser();

	TestRepositoryFileTransport testRepositoryFileTransport;
	testRepositoryFileTransport.runTestRepositoryFileTransport();

	TestRepositoryFileUser testRepositoryFileUser;
	testRepositoryFileUser.runTestRepositoryFileUser();

	TestService testService;
	testService.runTestService();

	TestException testException;
	testException.runTestException();

	TestValidationTransport testValidationtransport;
	testValidationtransport.runTestValidationTransport();

	TestValidationAirPlane testValidationAirPlane;
	testValidationAirPlane.runTestValidationAirPlane();

	TestValidationBus testValidationBus;
	testValidationBus.runTestValidationBus();

	Tests test;
	test.runTest();

	UserInterface userInterface;
	userInterface.runUserInterface();

	return 0;
}