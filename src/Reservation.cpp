#include "../header/Reservation.h"
#include "../header/Database.h"

unordered_map<ReservationStatus, string> Reservation::reservation_Status_Names = {
    {PENDING, "PENDING"},
    {REJECTED, "REJECTED"},
    {APPROVED, "APPROVED"}};

// Constructor
Reservation::Reservation(int _reservationId, int _price, const string &_purpose, string _date, int _hour, Person *_customer, const ConferenceHall &_conferenceHall)
    : reservationId(_reservationId), price(_price), purpose(_purpose), date(_date), hour(_hour), customer(_customer), conferenceHall(_conferenceHall), status(PENDING)
{
    Database::reservations.push_back(*this);
}

// Getter and Setter functions
int Reservation::getReservationId() const
{
    return reservationId;
}

void Reservation::setReservationId(int _reservationId)
{
    reservationId = _reservationId;
}

int Reservation::getPrice() const
{
    return price;
}

void Reservation::setPrice(int _price)
{
    price = _price;
}

const string &Reservation::getPurpose() const
{
    return purpose;
}

void Reservation::setPurpose(const string &_purpose)
{
    purpose = _purpose;
}

const string &Reservation::getDate() const
{
    return date;
}

// Setter fonksiyonu
void Reservation::setDate(const string &_date)
{
    if (isValidDate(_date))
    {
        date = _date;
    }
    else
    {
        cerr << "Invalid date format. Please use dd/yyyy format.\n";
    }
}

int Reservation::getHour() const
{
    return hour;
}

void Reservation::setHour(int _hour)
{
    hour = _hour;
}

Person *Reservation::getCustomer() const
{
    return customer;
}

void Reservation::setCustomer(Person *_customer)
{
    customer = _customer;
}

const ConferenceHall &Reservation::getConferenceHall() const
{
    return conferenceHall;
}

void Reservation::setConferenceHall(const ConferenceHall &_conferenceHall)
{
    conferenceHall = _conferenceHall;
}

ReservationStatus Reservation::getStatus() const
{
    return status;
}

void Reservation::setStatus(ReservationStatus _status)
{
    status = _status;
}
