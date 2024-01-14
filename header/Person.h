#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person
{
protected:
    int id;
    string name;
    string surname;
    string password;
    string username;

public:
    Person(int _id, const string &_name, const string &_surname, const string &_password, const string &_username);
    Person();
    ~Person();

    // Getter and Setter Functions
    int getId() const;
    void setId(int _id);
    const string &getName() const;
    void setName(const string &_name);
    const string &getSurname() const;
    void setSurname(const string &_surname);
    const string &getPassword() const;
    void setPassword(const string &_password);
    const string &getUsername() const;
    void setUsername(const string &_username);

    virtual void displayInfo() const = 0;
};

#endif // PERSON_H
