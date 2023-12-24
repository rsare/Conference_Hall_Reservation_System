#include "reservation.h"
#include "customer.h"
#include "conferenceHall.h"
#include "database.h"
#include <iostream>
#include <string>

//using namespace std;

Reservation::Reservation(int reservationId, int price, const string &purpose, int date, int hour, Customer customer, ConferenceHall conferenceHall)
    : reservationId(reservationId), price(price), purpose(purpose), date(date), hour(hour), customer(customer), conferenceHall(conferenceHall)
{
    Database::reservations.push_back(*this);
}

Reservation::Reservation() {}