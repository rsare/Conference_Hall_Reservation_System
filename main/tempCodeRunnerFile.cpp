#include <iostream>
#include <string>
#include "../src/Person.cpp"
#include "../src/AuditoriumOwner.cpp"
#include "../src/Customer.cpp"
#include "../src/ConferenceHall.cpp"
#include "../src/Reservation.cpp"
#include "../src/Database.cpp"
using namespace std;

int main()
{
    Person *admin = new AuditoriumOwner(0, "sare", "bayram", "123", "sare");
    cout << admin->getName() << endl;
    Person *customer1 = new Customer(1, "zahid", "baltaci", "123", "zahid");
    cout << customer1->getName() << endl;

    Database::person.push_back(admin);
    Database::person.push_back(customer1);

    ConferenceHall conferenceHall1(0, "testHall", 1000, MEDIUM_SALOON);
    Database::saloonKnowledge.push_back(conferenceHall1);

    cout << Database::saloonKnowledge[0].getHallName() << endl;

    Reservation reservation1(0, 1500, "test", 2023, 12, customer1, conferenceHall1);
    Database::reservations.push_back(reservation1);

    cout << Database::reservations[0].getCustomer()->getName() << endl;

    return 0;
}