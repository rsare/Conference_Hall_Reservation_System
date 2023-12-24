#ifndef CUSTOMER_H
#define CUSTOMER_H


#include "person.h"

class Customer : public Person{

public:
Customer(int id, const string &firstName, const string &lastName, const string &username, const string &password);
Customer();


};


#endif