#ifndef RESERVATION_H
#define RESERVATION_H
#include "customer.h"
#include "conferenceHall.h"

class Reservation
{

public:
    Reservation(int reservationId, int price, const string &purpose, int date, int hour, Customer customer, ConferenceHall conferenceHall);
    Reservation();


    int getReservationId() const;
    int getPrice() const;
    string getPurpose() const;
    int getDate() const;
    int getHour() const;
    Customer getCustomer() const;
    ConferenceHall getConferenceHall() const;

    void setReservationId(int newReservationId);
    void setPrice(int newPrice);
    void setPurpose(const string &newPurpose);
    void setDate(int newDate);
    int setHour(int newHour);
    void setCustomer(Customer newCustomer);
    void setConferenceHall(ConferenceHall newConferenceHall);



private:
    int reservationId;
    int price;
    string purpose;
    int date;
    int hour;
    Customer customer;
    ConferenceHall conferenceHall;
};

#endif