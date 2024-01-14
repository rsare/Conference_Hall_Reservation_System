#include "../header/Database.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>

vector<Person *> Database::person;
int Database::personCount = 0;
int Database::personId = 0;

vector<ConferenceHall> Database::saloonKnowledge;
int Database::conferenceHallId = 0;

vector<Reservation> Database::reservations;
int Database::reservationId = 0;

template <typename Base, typename Derived>
static bool instanceof (const Derived *ptr)
{
    return dynamic_cast<const Base *>(ptr) != nullptr;
}

Person *Database::login(const string &username, const string &password)
{
    for (int i = 0; i < Database::person.size(); i++)
    {
        if (Database::person[i]->getUsername() == username && Database::person[i]->getPassword() == password)
        {
            return Database::person[i];
        }
    }
    return nullptr;
}

// Functions about AuditoriumOwner
void Database::insertAuditoriumOwner(AuditoriumOwner auditoriumOwner)
{
    ofstream file("../txtFiles/AuditoriumOwner.txt", ios_base::app);

    if (!file.is_open())
    {
        cerr << "Error: Unable to open the file." << std::endl;
        return;
    }

    file << auditoriumOwner.getId() << '\n'
         << auditoriumOwner.getName() << '\n'
         << auditoriumOwner.getSurname() << '\n'
         << auditoriumOwner.getPassword() << '\n'
         << auditoriumOwner.getUsername() << '\n';

    personCount++;

    file.close();
    cout << "AuditoriumOwner has been written to the file successfully." << endl;
}

int Database::readAuditoriumOwner()
{
    ifstream file("../txtFiles/AuditoriumOwner.txt");
    if (!file.is_open())
    {
        cerr << "Error while opening the file!" << endl;
        return 1;
    }

    char chunk[128];
    int lineNum = 0;
    int userCount = 0;
    AuditoriumOwner *auditoriumOwner = nullptr;

    while (file.getline(chunk, sizeof(chunk)))
    {
        int newline_pos = strcspn(chunk, "\n");
        chunk[newline_pos] = '\0';

        if (lineNum % 5 == 0)
        {
            auditoriumOwner = new AuditoriumOwner;
            auditoriumOwner->setId(atoi(chunk));
            lineNum++;
        }
        else if (lineNum % 5 == 1)
        {
            auditoriumOwner->setName(chunk);
            lineNum++;
        }
        else if (lineNum % 5 == 2)
        {
            auditoriumOwner->setSurname(chunk);
            lineNum++;
        }
        else if (lineNum % 5 == 3)
        {
            auditoriumOwner->setPassword(chunk);
            lineNum++;
        }
        else if (lineNum % 5 == 4)
        {
            auditoriumOwner->setUsername(chunk);
            lineNum++;
            Database::person.push_back(auditoriumOwner);
            userCount++;
        }
    }
    personCount = userCount;
    file.close();
    return 0;
}

int Database::TotalProfit()
{
    int totalProfit = 0;

    for (const Reservation &reservation : reservations)
    {
        if (reservation.getStatus() == APPROVED)
        {
            totalProfit += reservation.getPrice();
        }
    }
    return totalProfit;
}
// Functions about Customer
void Database::insertCustomer(Customer customer)
{

    ofstream file("../txtFiles/Customer.txt", ios_base::app);

    if (!file.is_open())
    {
        cerr << "Error: Unable to open the file." << std::endl;
        return;
    }

    file << customer.getId() << '\n'
         << customer.getName() << '\n'
         << customer.getSurname() << '\n'
         << customer.getPassword() << '\n'
         << customer.getUsername() << '\n';

    personCount++;

    file.close();
    cout << "Customer has been written to the file successfully." << endl;
}

int Database::readCustomer()
{
    ifstream file("../txtFiles/Customer.txt");
    if (!file.is_open())
    {
        cerr << "Error while opening the file!" << endl;
        return 1;
    }

    char chunk[128];
    int lineNum = 0;
    int userCount = 0;
    Customer *customer = nullptr;

    while (file.getline(chunk, sizeof(chunk)))
    {
        int newline_pos = strcspn(chunk, "\n");
        chunk[newline_pos] = '\0';

        if (lineNum % 5 == 0)
        {
            customer = new Customer;
            customer->setId(atoi(chunk));
            lineNum++;
        }
        else if (lineNum % 5 == 1)
        {
            customer->setName(chunk);
            lineNum++;
        }
        else if (lineNum % 5 == 2)
        {
            customer->setSurname(chunk);
            lineNum++;
        }
        else if (lineNum % 5 == 3)
        {
            customer->setPassword(chunk);
            lineNum++;
        }
        else if (lineNum % 5 == 4)
        {
            customer->setUsername(chunk);
            lineNum++;
            Database::person.push_back(customer);
            userCount++;
        }
    }
    personCount = userCount;
    file.close();
    return 0;
}

int Database::deleteCustomer(int customerId)
{
    int checkId = 0;

    if (customerId < 0 || customerId > personId)
    {
        cout << "Please enter a valid number!" << endl;
        return 0;
    }

    ifstream file("../txtFiles/Customer.txt");
    ofstream temp("../txtFiles/temp.txt");

    if (!file.is_open() || !temp.is_open())
    {
        cout << "Error while opening the file!";
        return 1;
    }

    Customer *customer = nullptr;
    vector<Person *> tempUsers;
    tempUsers.push_back(Database::person[0]);
    char chunk[128];
    int lineNum = 0;
    bool skipPerson = false;

    while (file.getline(chunk, sizeof(chunk)))
    {
        if (lineNum % 5 == 0)
        {
            customer = new Customer;
            customer->setId(atoi(chunk));
            if (customer->getId() == customerId)
            {
                skipPerson = true;
                // Eğer müşteri siliniyorsa, rezervasyonları da sil
                for (auto it = reservations.begin(); it != reservations.end();)
                {
                    if (dynamic_cast<Customer *>(it->getCustomer())->getId() == customerId)
                    {
                        it = reservations.erase(it);
                    }
                    else
                    {
                        ++it;
                    }
                }
            }
            else
            {
                temp << customer->getId() << "\n";
            }
            lineNum++;
        }
        else if (lineNum % 5 == 1)
        {
            customer->setName(chunk);
            if (!skipPerson)
            {
                temp << customer->getName() << "\n";
            }
            lineNum++;
        }
        else if (lineNum % 5 == 2)
        {
            customer->setSurname(chunk);
            if (!skipPerson)
            {
                temp << customer->getSurname() << "\n";
            }
            lineNum++;
        }
        else if (lineNum % 5 == 3)
        {
            customer->setPassword(chunk);
            if (!skipPerson)
            {
                temp << customer->getPassword() << "\n";
            }
            lineNum++;
        }
        else if (lineNum % 5 == 4)
        {
            customer->setUsername(chunk);
            if (!skipPerson)
            {
                temp << customer->getUsername() << "\n";
                tempUsers.push_back(customer);
            }
            skipPerson = false;
            lineNum++;
        }
    }

    file.close();
    temp.close();

    remove("../txtFiles/Customer.txt");
    rename("../txtFiles/temp.txt", "../txtFiles/Customer.txt");

    // Update users vector
    Database::person = tempUsers;
    personCount = tempUsers.size();

    cout << "\nCustomers has been deleted successfully\n";

    return 0;
}

int Database::updateCustomerInformation(const int id, const string &newName, const string &newSurname, const string &newPassword, const string &newUsername)

{
    if (id < 0 || id >= personId)
    {
        cout << "Please enter a valid number!" << endl;
        return 0;
    }

    Customer *customer;
    ofstream file("../txtFiles/Customer.txt", ofstream::out | ofstream::trunc);
    file.close();

    for (int i = 0; i < Database::person.size(); i++)
    {
        if (instanceof <Customer>(Database::person[i]))
        {
            customer = static_cast<Customer *>(Database::person[i]);
            Database::insertCustomer(*customer);
        }
    }

    cout << "Customer information has been updated successfully!" << endl;
}

void Database::showCustomerReservations(const Customer &customer)
{
    cout << "Reservations for Customer: " << customer.getName() << " " << customer.getSurname() << endl
         << endl;

    for (const Reservation &reservation : reservations)
    {
        if (reservation.getCustomer()->getId() == customer.getId())
        {
            // Eğer rezervasyon müşteriye aitse, bilgilerini ekrana yazdır
            cout << "Reservation ID: " << reservation.getReservationId() << endl;
            cout << "Price: " << reservation.getPrice() << endl;
            cout << "Purpose: " << reservation.getPurpose() << endl;
            cout << "Date: " << reservation.getDate() << endl;
            cout << "Hour: " << reservation.getHour() << endl;
            cout << "Conference Hall Name : " << reservation.getConferenceHall().getHallName() << endl;
            cout << "Reservation Status : " << Reservation::reservation_Status_Names[reservation.getStatus()] << endl;

            cout << "--------------------------" << endl;
        }
    }
}
// Functions about Conference Hall
void Database::displayAllConferenceHalls()
{
    cout << "All Conference Halls\n\n";

    for (const auto &hall : saloonKnowledge)
    {
        hall.displayInfo();
        cout << "------------------------------\n";
    }
}

void Database::deleteConferenceHall(int hallId)
{
    // ConferenceHall'ı bul
    auto it = std::find_if(saloonKnowledge.begin(), saloonKnowledge.end(), [hallId](const ConferenceHall &hall)
                           { return hall.getId() == hallId; });

    if (it != saloonKnowledge.end())
    {
        // ConferenceHall'ı bulduk, şimdi reservation'ları sil
        auto reservationsToDelete = remove_if(reservations.begin(), reservations.end(), [hallId](const Reservation &reservation)
                                              { return reservation.getConferenceHall().getId() == hallId; });

        // reservations vector'ından sil
        reservations.erase(reservationsToDelete, reservations.end());

        // ConferenceHall'ı vector'dan sil
        saloonKnowledge.erase(it);
        cout << "ConferenceHall with ID " << hallId << " has been deleted.\n";
    }
    else
    {
        std::cout << "ConferenceHall with ID " << hallId << " not found.\n";
    }
}

void Database::updateConferenceHall(int hall_id, const string &hallName, int hallCapacity, SaloonType saloonType)
{
    // ConferenceHall'ı bul
    auto it = find_if(saloonKnowledge.begin(), saloonKnowledge.end(), [hall_id](const ConferenceHall &hall)
                      { return hall.getId() == hall_id; });

    if (it != saloonKnowledge.end())
    {
        // ConferenceHall'ı bulduk, güncelle
        it->setHallName(hallName);
        it->setHallCapacity(hallCapacity);
        it->setSaloonType(saloonType);
        cout << "ConferenceHall with ID " << hall_id << " has been updated.\n";
    }
    else
    {
        cout << "ConferenceHall with ID " << hall_id << " not found.\n";
    }
}

// Functions about Reservation
void Database::createReservation(int _price, const string &_purpose, const string &_date, int _hour, Person *_customer, const ConferenceHall &_conferenceHall)
{
    // Girişi kontrol et
    if (!Reservation::isValidDate(_date))
    {
        cout << "Invalid date format. Please use the format MM/YYYY.\n";
        return;
    }

    // Check if the hall and time are available for reservation
    for (const Reservation &reservation : reservations)
    {
        if (reservation.getConferenceHall().getId() == _conferenceHall.getId() &&
            reservation.getDate() == _date &&
            reservation.getHour() == _hour &&
            reservation.getStatus() == 1)
        {
            cout << "Warning: The selected hall is already reserved for the specified date and hour.\n";
            return;
        }
    }

    // Create the reservation
    Reservation newReservation(reservationId++, _price, _purpose, _date, _hour, _customer, _conferenceHall);

    cout << "Reservation request created successfully.\n";
}

void Database::showAllReservations()
{
    cout << "All Reservations\n\n";

    if (reservations.empty())
    {
        cout << "No reservations available.\n";
        return;
    }

    for (const Reservation &reservation : reservations)
    {
        cout << "Reservation ID: " << reservation.getReservationId() << endl;
        cout << "Price: " << reservation.getPrice() << "$\n";
        cout << "Purpose: " << reservation.getPurpose() << endl;
        cout << "Date: " << reservation.getDate() << endl;
        cout << "Hour: " << reservation.getHour() << endl;
        cout << "Customer: " << reservation.getCustomer()->getName() << " " << reservation.getCustomer()->getSurname() << endl;
        cout << "Conference Hall: " << reservation.getConferenceHall().getHallName() << " (Capacity: " << reservation.getConferenceHall().getHallCapacity() << ")\n";
        cout << "Status: " << Reservation::reservation_Status_Names[reservation.getStatus()] << "\n";
        cout << "------------------------------\n";
    }
}

void Database::deleteReservation(int reservationId)
{
    auto it = find_if(reservations.begin(), reservations.end(), [reservationId](const Reservation &reservation)
                      { return reservation.getReservationId() == reservationId; });

    if (it != reservations.end())
    {
        // Rezervasyonu vektörden sil
        reservations.erase(it);
        cout << "Reservation has been deleted.\n";
    }
    else
    {
        cout << "Reservation not found.\n";
    }
}

void Database::updateReservation(int reservationId, int _price, const string &_purpose, const string &_date, int _hour, const ConferenceHall &_conferenceHall)
{
    auto it = find_if(reservations.begin(), reservations.end(), [reservationId](const Reservation &reservation)
                      { return reservation.getReservationId() == reservationId; });

    if (it != reservations.end())
    {
        // Rezervasyonu bulduk, güncelleme işlemlerini yapalım
        Reservation &targetReservation = *it;

        // Güncelleme işlemleri
        targetReservation.setPrice(_price);
        targetReservation.setPurpose(_purpose);
        targetReservation.setDate(_date);
        targetReservation.setHour(_hour);
        targetReservation.setConferenceHall(_conferenceHall);

        cout << "Reservation has been updated.\n";
    }
    else
    {
        cout << "Reservation not found.\n";
    }
}

const ConferenceHall *Database::getConferenceHallById(int hallId)
{
    for (const ConferenceHall &hall : saloonKnowledge)
    {
        if (hall.getId() == hallId)
        {
            return &hall;
        }
    }
    return nullptr; // ID'ye sahip konferans salonu bulunamadı
}

void Database::setIdNumbers()
{
    // For user
    int maxForUser = Database::person[0]->getId();
    for (int i = 0; i < Database::person.size(); i++)
    {
        if (maxForUser < Database::person[i]->getId())
        {
            maxForUser = Database::person[i]->getId();
        }
    }
    Database::personId = maxForUser + 1;
}
