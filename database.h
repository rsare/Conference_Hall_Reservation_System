#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <vector>
#include "person.h"
#include "reservation.h"
#include "conferenceHall.h"

using namespace std;

class Database{

public:
static vector <Person> person;
static vector <Reservation> reservations;
static vector <ConferenceHall> saloonKnowledge;
static int personCount;
static int reservationCount;
static int conferenceHallCount;


static void readConferenceHall();
static void deleteConferenceHall(int confHallId);
static void displayAllReservations(const Reservation *reservations, int reservationCount);





} ;





#endif DATABASE_H