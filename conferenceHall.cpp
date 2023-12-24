#include <iostream>
#include <string>
#include "conferenceHall.h"

ConferenceHall::ConferenceHall(int id, const string &hallName, int hallCapacity)
    : id(id), hallName(hallName), hallCapacity(hallCapacity)
{
}

ConferenceHall::ConferenceHall() {}
ConferenceHall::~ConferenceHall() {}

int ConferenceHall::getId() const
{
    return id;
}

string ConferenceHall::getHallName() const
{
    return hallName;
}

int ConferenceHall::getHallCapacity() const
{
    return hallCapacity;
}

void ConferenceHall::setId(int newId)
{
    id = newId;
}

void ConferenceHall::setHallName(const string &newHallName)
{
    hallName = newHallName;
}

void ConferenceHall::setHallCapacity(int newHallCapacity)
{
    hallCapacity = newHallCapacity;
}