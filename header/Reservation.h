#ifndef RESERVATION_H
#define RESERVATION_H

#include "Person.h"
#include "Customer.h"
#include "ConferenceHall.h"
#include <unordered_map>

enum ReservationStatus
{
    PENDING,
    APPROVED,
    REJECTED
};

class Reservation
{
private:
    int reservationId;
    int price;
    string purpose;
    string date;
    int hour;
    Person *customer;
    ConferenceHall conferenceHall;
    ReservationStatus status;

public:
    // Constructor
    Reservation(int _reservationId, int _price, const string &_purpose, string _date, int _hour, Person *_customer, const ConferenceHall &_conferenceHall);
    static unordered_map<ReservationStatus, string> reservation_Status_Names;
    static bool isValidDate(const string& date);
    // Getter and Setter functions
    int getReservationId() const;
    void setReservationId(int _reservationId);
    int getPrice() const;
    void setPrice(int _price);
    const string &getPurpose() const;
    void setPurpose(const string &_purpose);
    const string& getDate() const;
    void setDate(const string& _date);
    int getHour() const;
    void setHour(int _hour);
    Person *getCustomer() const;
    void setCustomer(Person *_customer);
    const ConferenceHall &getConferenceHall() const;
    void setConferenceHall(const ConferenceHall &_conferenceHall);
    ReservationStatus getStatus() const;
    void setStatus(ReservationStatus _status);
};

#endif // RESERVATION_H
