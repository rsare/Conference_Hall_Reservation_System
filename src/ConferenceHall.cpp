#include "../header/ConferenceHall.h"
#include "../header/Database.h"
#include <regex>

// Constructor
ConferenceHall::ConferenceHall(int _id, const string &_hallName, int _hallCapacity, SaloonType _saloonType)
    : id(_id), hallName(_hallName), hallCapacity(_hallCapacity), saloonType(_saloonType)
{
    Database::saloonKnowledge.push_back(*this);
}

ConferenceHall::ConferenceHall() {}

unordered_map<SaloonType, string> ConferenceHall::sallon_Type_Names = {
    {SMALL_SALOON, "SMALL SALOON"},
    {MEDIUM_SALOON, "MEDIUM SALOON"},
    {LARGE_SALOON, "LARGE_SALOON"}};

void ConferenceHall::displayInfo() const
{
    cout << "Hall ID: " << id << '\n'
         << "Hall Name: " << hallName << '\n'
         << "Hall Capacity: " << hallCapacity << '\n'
         << "Saloon Type: " << sallon_Type_Names[saloonType] << '\n';
}

bool Reservation::isValidDate(const string &date)
{
    std::regex dateRegex(R"(\d{2}/\d{4})");
    return regex_match(date, dateRegex);
}

// Getter and Setter functions
int ConferenceHall::getId() const
{
    return id;
}

void ConferenceHall::setId(int _id)
{
    id = _id;
}

const string &ConferenceHall::getHallName() const
{
    return hallName;
}

void ConferenceHall::setHallName(const string &_hallName)
{
    hallName = _hallName;
}

int ConferenceHall::getHallCapacity() const
{
    return hallCapacity;
}

void ConferenceHall::setHallCapacity(int _hallCapacity)
{
    hallCapacity = _hallCapacity;
}

SaloonType ConferenceHall::getSaloonType() const
{
    return saloonType;
}

void ConferenceHall::setSaloonType(SaloonType _saloonType)
{
    saloonType = _saloonType;
}
