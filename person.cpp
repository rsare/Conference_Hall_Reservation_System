#include <iostream>
#include <string>
#include <vector>
#include "person.h"

using namespace std;

Person::Person(int id, const string &firstName, const string &lastName, const string &username, const string &password)
    : id(id), firstName(firstName), lastName(lastName), username(username), password(password)
{
}


Person::Person()
{
}

Person::~Person()
{
}

int Person::getId() const
{
    return id;
}
string Person::getFirstName() const
{
    return firstName;
}

string Person::getLastName() const
{
    return lastName;
}

string Person::getUsername() const
{
    return username;
}

string Person::getPassword() const
{
    return password;
}


void Person::setId(int newId)
{
    id = newId;
}

void Person::setFirstName(const string &newFirstName)
{
    firstName = newFirstName;
}

void Person::setLastName(const string &newLastName)
{
    lastName = newLastName;
}

void Person::setUsername(const string &newUsername)
{
    username = newUsername;
}

void Person::setPassword(const string &newPassword)
{
    password = newPassword;
}
