#include "TestRepositoryFileUser.h"
#include <cassert>

TestRepositoryFileUser::TestRepositoryFileUser()
{
	User user("irina14", "ai2000");
	this->usersIn.push_back(user);
}

TestRepositoryFileUser::~TestRepositoryFileUser()
{
}

void TestRepositoryFileUser::testAddItem()
{
	RepositoryFileUser repositoryFileUser(this->fileNameInTXT, this->fileNameOutTXT);
	User user("irina14", "ai2000");
	repositoryFileUser.addItem(user);
	assert(repositoryFileUser.getItem(0) == user);
}

void TestRepositoryFileUser::testUpdateItem()
{
	RepositoryFileUser repositoryFileUser(this->fileNameInTXT, this->fileNameOutTXT);
	User user1("irina14", "ai2000");
	repositoryFileUser.addItem(user1);
	User user2("teodor.pop2008", "bw2008");
	assert(repositoryFileUser.getItem(0) == user1);
	repositoryFileUser.updateItem(user1, user2);
	assert(repositoryFileUser.getItem(0) == user2);
}

void TestRepositoryFileUser::testDeleteItem()
{
	RepositoryFileUser repositoryFileUser(this->fileNameInTXT, this->fileNameOutTXT);
	User user1("irina14", "ai2000");
	repositoryFileUser.addItem(user1);
	User user2("teodor.pop2008", "bw2008");
	repositoryFileUser.deleteItem(user2);
	assert(repositoryFileUser.getSize() == 3);
	assert(repositoryFileUser.getItem(0) == user1);
	repositoryFileUser.deleteItem(user1);
	assert(repositoryFileUser.getSize() == 1);
}

void TestRepositoryFileUser::testGetAll()
{
	RepositoryFileUser repositoryFileUser(this->fileNameInTXT, this->fileNameOutTXT);
	User user("irina14", "ai2000");
	repositoryFileUser.addItem(user);
	vector<User> users = repositoryFileUser.getAll();
	assert(users[0] == user);
}

void TestRepositoryFileUser::testGetSize()
{
	RepositoryFileUser repositoryFileUser(this->fileNameInTXT, this->fileNameOutTXT);
	assert(repositoryFileUser.getSize() == 3);
}

void TestRepositoryFileUser::testGetItem()
{
	RepositoryFileUser repositoryFileUser(this->fileNameInTXT, this->fileNameOutTXT);
	User user1("irina14", "ai2000");
	repositoryFileUser.addItem(user1);
	assert(repositoryFileUser.getItem(0) == user1);
	User user2("teodor.pop2008", "bw2008");
	repositoryFileUser.addItem(user2);
	assert(repositoryFileUser.getItem(1) == user2);
}

void TestRepositoryFileUser::testFindItem()
{
	RepositoryFileUser repositoryFileUser(this->fileNameInTXT, this->fileNameOutTXT);
	User user("irina14", "ai2000");
	repositoryFileUser.addItem(user);
	assert(repositoryFileUser.findItem(user) != -1);
	assert(repositoryFileUser.findItem(user) == 0);
}

void TestRepositoryFileUser::testLoadFromFileTXT()
{
	RepositoryFileUser repositoryFileUser(this->fileNameInTXT, this->fileNameOutTXT);
	repositoryFileUser.loadFromFile();
	User user1("irina14", "ai2000");
	User user2("teodor.pop2008", "bw2008");
	repositoryFileUser.addItem(user1);
	repositoryFileUser.addItem(user2);
	repositoryFileUser.saveToFile();
}

void TestRepositoryFileUser::testSavetoFileTXT()
{
	RepositoryFileUser repositoryFileUser(this->fileNameInTXT, this->fileNameOutTXT);
	repositoryFileUser.loadFromFile();
	User user("daria.catherine", "katy");
	repositoryFileUser.addItem(user);
	repositoryFileUser.saveToFile();
}

void TestRepositoryFileUser::runTestRepositoryFileUser()
{
	this->testAddItem();
	this->testUpdateItem();
	this->testDeleteItem();
	this->testGetAll();
	this->testGetSize();
	this->testGetItem();
	this->testFindItem();
	this->testLoadFromFileTXT();
	this->testSavetoFileTXT();
} 