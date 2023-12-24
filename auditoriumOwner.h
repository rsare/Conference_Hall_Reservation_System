#ifndef AUDITORIUMOWNER_H
#define AUDITORIUMOWNER_H

#include "person.h"


class AuditoriumOwner : public Person{

public:
AuditoriumOwner(int id, const string &firstName, const string &lastName, const string &username, const string &password);
AuditoriumOwner();

static vector <Person> person;



};


#endif