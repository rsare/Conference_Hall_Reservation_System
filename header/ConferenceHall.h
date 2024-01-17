#ifndef CONFERENCEHALL_H
#define CONFERENCEHALL_H

#include <string>
#include <unordered_map>
using namespace std;

enum SaloonType
{
    SMALL_SALOON,
    MEDIUM_SALOON,
    LARGE_SALOON
};

class ConferenceHall
{
private:
    int id;
    string hallName;
    int hallCapacity;
    SaloonType saloonType;

public:
    // Constructor
    ConferenceHall(int _id, const string &_hallName, int _hallCapacity, SaloonType _saloonType);
    ConferenceHall();
    static unordered_map<SaloonType, string> sallon_Type_Names; //Enum'un ismini yazdırmak için kullanılan bir fonksiyon
    void displayInfo() const;

    // Getter and Setter functions
    int getId() const;
    void setId(int _id);
    const string &getHallName() const;
    void setHallName(const string &_hallName);
    int getHallCapacity() const;
    void setHallCapacity(int _hallCapacity);
    SaloonType getSaloonType() const;
    void setSaloonType(SaloonType _saloonType);
};

#endif // CONFERENCEHALL_H
