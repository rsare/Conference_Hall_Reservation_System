#ifndef AUDITORIUMOWNER_H
#define AUDITORIUMOWNER_H

#include "Person.h"
#include "Reservation.h"

class AuditoriumOwner : public Person
{
public:
    // Constructor
    AuditoriumOwner(int _id, const string &_name, const string &_surname, const string &_password, const string &_username);
    AuditoriumOwner();
    void displayInfo() const override;
};

#endif // AUDITORIUMOWNER_H
