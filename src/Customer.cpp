#include "../header/Customer.h"
#include "../header/Database.h"
#include <iostream>

using namespace std;


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

void operator++(Customer customer)
{
    for (Reservation reservation : Database::reservations)
    {
        if (reservation.getCustomer()->getId() == customer.getId())
        {
            cout << "Reservation ID: " << reservation.getReservationId() << endl;
            cout << "Price: " << reservation.getPrice() << endl;
            cout << "Purpose: " << reservation.getPurpose() << endl;
            cout << "Date: " << reservation.getDate() << endl;
            cout << "Hour: " << reservation.getHour() << endl;
            cout << "Status: " << Reservation::reservation_Status_Names[reservation.getStatus()] << endl;
            cout << "Conference Hall Name : " << reservation.getConferenceHall().getHallName() << endl;

            cout << "--------------------------" << endl;
        }
    }
}