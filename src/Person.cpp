#include "../header/Person.h"
#include "../header/Database.h"
#include <iostream>
using namespace std;

Person::Person(int _id, const string &_name, const string &_surname, const string &_password, const string &_username)
    : id(_id), name(_name), surname(_surname), password(_password), username(_username)
{
    Database::person.push_back(this);
}

Person::Person()
{
}

Person::~Person()
{
}

void Person::displayInfo() const
{
    cout << "Person Info: " << name << " " << surname << endl;
}

int Person::getId() const
{
    return id;
}

void Person::setId(int _id)
{
    id = _id;
}

const string &Person::getName() const
{
    return name;
}

void Person::setName(const string &_name)
{
    name = _name;
}

const string &Person::getSurname() const
{
    return surname;
}

void Person::setSurname(const string &_surname)
{
    surname = _surname;
}

const string &Person::getPassword() const
{
    return password;
}

void Person::setPassword(const string &_password)
{
    password = _password;
}

const string &Person::getUsername() const
{
    return username;
}

void Person::setUsername(const string &_username)
{
    username = _username;
}
