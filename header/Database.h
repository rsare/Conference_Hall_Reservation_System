#ifndef DATABASE_H
#define DATABASE_H

#include "Person.h"
#include "AuditoriumOwner.h"
#include "Customer.h"
#include "ConferenceHall.h"
#include "Reservation.h"
#include <vector>

class Database
{
public:
    static vector<Person *> person;
    static int personCount;
    static int personId;

    static vector<ConferenceHall> saloonKnowledge;
    static int conferenceHallId;

    static vector<Reservation> reservations;
    static int reservationId;

    static Person *login(const string &username, const string &password);

    // Functions about AuditoriumOwner
    static void insertAuditoriumOwner(AuditoriumOwner AuditoriumOwner);
    static int readAuditoriumOwner();
    static int TotalProfit();
    // Functions about Customer
    static void insertCustomer(Customer Customer);
    static int readCustomer();
    static int deleteCustomer(int customerId);
    static int updateCustomerInformation(const int id, const string &newName, const string &newSurname, const string &newPassword, const string &newUsername);
    static void setIdNumbers();
    // Functions about Conferenece Hall
    static void displayAllConferenceHalls();
    static void deleteConferenceHall(int hallId);
    static void updateConferenceHall(int hall_id, const string &hallName, int hallCapacity, SaloonType saloonType);
    // Functions about Reservations
    static void createReservation(int _price, const string &_purpose, const string &_date, int _hour, Person *_customer, const ConferenceHall &_conferenceHall);
    static void showAllReservations();
    static void deleteReservation(int reservationId);
    static void updateReservation(int reservationId, int _price, const string &_purpose, const string &_date, int _hour, const ConferenceHall &_conferenceHall);
    static const ConferenceHall *getConferenceHallById(int hallId);
};

#endif // DATABASE_H
