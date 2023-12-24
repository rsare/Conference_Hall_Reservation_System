#include "customer.h"


Customer::Customer(int id,const string &firstName, const string &lastName, const string &username, const string &password)
: Person(id, firstName, lastName, username, password){
}

Customer::Customer(){}