#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"

class Customer : public Person {
public:
    // Constructor
    Customer(int _id, const string& _name, const string& _surname, const string& _password, const string& _username);
    Customer();
    void displayInfo() const override;
    friend void operator++(Customer customer); //Show customer reservations with conference halls.
};

#endif // CUSTOMER_H