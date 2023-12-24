#ifndef PERSON_H
#define PERSON_H

using namespace std;
#include <string>

class Person
{

private:
    int id;
    string firstName;
    string lastName;
    string username;
    string password;



public:
    Person();
    Person(int id,const string &firstName, const string &lastName, const string &username, const string &password);


    int getId() const;
    string getFirstName() const;
    string getLastName() const;
    string getUsername() const;
    string getPassword() const;

    void setId(int newId);
    void setFirstName(const string &newFirstName);
    void setLastName(const string &newLastName);
    void setUsername(const string &newUsername);
    void setPassword(const string &newPassword);


};

#endif
