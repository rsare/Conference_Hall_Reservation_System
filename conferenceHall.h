#ifndef CONFERENCEHALL_H
#define CONFERENCEHALL_H


class ConferenceHall
{

public:
    enum saloonsType
    {

        SMALL_SALOON,
        MEDIUM_SALOON,
        LARGE_SALOON

    };

    ConferenceHall(int id, const string &hallName, int hallCapacity);
    ConferenceHall();

    int getId() const;
    string getHallName() const;
    int getHallCapacity() const;

    void setId(int newId);
    void setHallName(const string &newHallName);
    void setHallCapacity(int newHallCapacity);

private:
    int id;
    string hallName;
    int hallCapacity;
};

#endif