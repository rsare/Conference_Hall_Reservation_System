#include "../header/Customer.h"

Customer::Customer(int _id, const string &_name, const string &_surname, const string &_password, const string &_username)
    : Person(_id, _name, _surname, _password, _username)
{
    Database::insertCustomer(*this);
}
Customer::Customer() {}

void Customer::displayInfo() const
{
    cout << "Customer Info: " << getName() << " " << getSurname() << endl;
}