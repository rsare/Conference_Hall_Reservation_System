#include "../header/AuditoriumOwner.h"
#include "../header/Database.h"
using namespace std;

AuditoriumOwner::AuditoriumOwner(int _id, const string &_name, const string &_surname, const string &_password, const string &_username)
    : Person(_id, _name, _surname, _password, _username)
{
    Database::insertAuditoriumOwner(*this);
}

AuditoriumOwner::AuditoriumOwner() {}

void AuditoriumOwner::displayInfo() const
{
    cout << "AuditoriumOwner Info: " << getName() << " " << getSurname() << endl;
}

