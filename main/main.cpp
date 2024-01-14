#include <iostream>
#include <string>
#include "../src/Person.cpp"
#include "../src/AuditoriumOwner.cpp"
#include "../src/Customer.cpp"
#include "../src/ConferenceHall.cpp"
#include "../src/Reservation.cpp"
#include "../src/Database.cpp"
using namespace std;

int Display();
void defaultInformation();

int main()
{
    defaultInformation();

    Database::readAuditoriumOwner();
    Database::readCustomer();
    Database::setIdNumbers();
    Display();

    return 0;
}

int Display()
{
    Person *account;
    int option;
    int isLoggedIn = 0;

    while (true)
    {
        if (isLoggedIn && (instanceof <AuditoriumOwner>(account)))
        {
            cout << "\n--------- Welcome Auditorium Owner ---------\n";

            ConferenceHall newHall;
            int choice = 0;
            int hall_id = 0;
            string hallName = "";
            int hallCapacity = 0;
            SaloonType hallType;
            int typeInput = 0;
            int approveOrRejectId = 0;
            int choiceAprroveOrRejected = 0;
            int idForDeleteCustomer = 0;

            cout << "\n1- Create a new conference hall" << endl;
            cout << "2- Show all conference halls" << endl;
            cout << "3- Update a conference hall" << endl;
            cout << "4- Delete conference hall" << endl;
            cout << "5- Show all reservations" << endl;
            cout << "6- Approved or rejected reservation request" << endl;
            cout << "7- Delete customer account" << endl;
            cout << "8- Show Total Profit" << endl;
            cout << "9- Logout" << endl;

            cout << "\nSelect an option : ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Please enter your conference hall name: ";
                cin >> hallName;

                cout << "Please enter your hall capacity: ";
                cin >> hallCapacity;

                cout
                    << "1- SMALL SALOON" << endl
                    << "2- MEDIUM SALOON" << endl
                    << "3- LARGE SALOON" << endl;

                cout << "Please enter your hall type : ";
                cin >> typeInput;

                switch (typeInput)
                {
                case 1:
                    hallType = SMALL_SALOON;
                    break;
                case 2:
                    hallType = MEDIUM_SALOON;
                    break;
                case 3:
                    hallType = LARGE_SALOON;
                    break;
                default:
                    cerr << "Invalid hall type input. Exiting...\n";
                    return 1;
                }
                newHall = ConferenceHall(Database::conferenceHallId++, hallName, hallCapacity, hallType);
                cout << "Conference hall created successfully" << endl;
                break;

            case 2:
                Database::displayAllConferenceHalls();
                break;

            case 3:
                for (int i = 0; i < Database::saloonKnowledge.size(); i++)
                {
                    cout << endl
                         << (i + 1) << "- Name of the Conference Hall : " << Database::saloonKnowledge[i].getHallName() << " / ID of Conference Hall : " << Database::saloonKnowledge[i].getId();
                }
                cout << "\n\nPlease write the ID of the conference hall you want to update :";
                cin >> hall_id;
                cout << "Please enter your new conference hall name: ";
                cin >> hallName;

                cout << "Please enter your new hall capacity: ";
                cin >> hallCapacity;

                cout
                    << "1- SMALL SALOON" << endl
                    << "2- MEDIUM SALOON" << endl
                    << "3- LARGE SALOON" << endl;

                cout << "Please enter your new hall type : ";
                cin >> typeInput;

                switch (typeInput)
                {
                case 1:
                    hallType = SMALL_SALOON;
                    break;
                case 2:
                    hallType = MEDIUM_SALOON;
                    break;
                case 3:
                    hallType = LARGE_SALOON;
                    break;
                default:
                    cerr << "Invalid hall type input. Exiting...\n";
                    return 1;
                }
                Database::updateConferenceHall(hall_id, hallName, hallCapacity, hallType);
                break;

            case 4:
                for (int i = 0; i < Database::saloonKnowledge.size(); i++)
                {
                    cout << endl
                         << (i + 1) << "- Name of the Conference Hall : " << Database::saloonKnowledge[i].getHallName() << " / ID of Conference Hall : " << Database::saloonKnowledge[i].getId();
                }
                cout << "\n\nPlease write the ID of the conference hall you want to delete :";
                cin >> hall_id;
                Database::deleteConferenceHall(hall_id);
                break;

            case 5:
                Database::showAllReservations();
                break;

            case 6:

                if (Database::reservations.empty())
                {
                    cout << "No reservations available.\n";
                    break;
                }

                for (const Reservation &reservation : Database::reservations)
                {
                    if (reservation.getStatus() == PENDING) // Write just pending status
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

                cout << "\n\nPlease write the ID of the reservation you want approve or reject : ";
                cin >> approveOrRejectId;

                cout << "\n1- Approve" << endl;
                cout << "2- Reject" << endl;

                cout << "Please enter your choice : ";
                cin >> choiceAprroveOrRejected;

                switch (choiceAprroveOrRejected)
                {
                case 1:
                    for (int i = 0; i < Database::reservations.size(); i++)
                    {
                        if (Database::reservations[i].getReservationId() == approveOrRejectId)
                        {
                            Database::reservations[i].setStatus(APPROVED);
                        }
                    }
                    break;
                case 2:
                    for (int i = 0; i < Database::reservations.size(); i++)
                    {
                        if (Database::reservations[i].getReservationId() == approveOrRejectId)
                        {
                            Database::reservations[i].setStatus(REJECTED);
                        }
                    }
                    break;
                default:
                    cerr << "Invalid hall type input. Exiting...\n";
                    return 1;
                }
                break;
            case 7:
                for (int i = 0; i < Database::person.size(); i++)
                {
                    if (instanceof <Customer>(Database::person[i]))
                    {
                        cout << endl
                             << i << "- Username : " << Database::person[i]->getUsername() << " / ID of User : " << Database::person[i]->getId();
                    }
                }

                cout << "\nPlease enter the ID of the customer which you want to delete : ";
                cin >> idForDeleteCustomer;

                Database::deleteCustomer(idForDeleteCustomer);
                break;
            case 8:
                cout << "Total Profit : " << Database::TotalProfit() << endl;
                break;
            case 9:
                isLoggedIn = 0;
                break;
            default:
                printf("\nInvalid option. Please select [1-9]\n");
                while (getchar() != '\n')
                    ;
                break;
            }
        }
        else if (isLoggedIn && (instanceof <Customer>(account)))
        {
            int switchOption = 0;
            string newName;
            string newSurname;
            string newPassword;
            string newUsername;
            Customer *customerAccount = dynamic_cast<Customer *>(account);

            int price = 0;
            string purpose;
            string date;
            int hour;
            int selectedHallId = 0;
            int conferenceHallId = 0;
            const ConferenceHall *selectedHall;

            cout << "\n--------- Welcome " << account->getName() << " --------- " << endl;

            cout << "\n1- Show customer information" << endl;
            cout << "2- Update customer information" << endl;
            cout << "3- Create reservation" << endl;
            cout << "4- Update reservation" << endl;
            cout << "5- Show reservation" << endl;
            cout << "6- Logout" << endl;

            cout << "\nSelect an option : ";
            cin >> switchOption;

            switch (switchOption)
            {
            case 1:
                cout << "\nName : " << account->getName() << endl;
                cout << "Surname : " << account->getSurname() << endl;
                cout << "Password : " << account->getPassword() << endl;
                cout << "Username : " << account->getUsername() << endl;
                break;
            case 2:
                cout << "\nPlease enter your new name : ";
                cin >> newName;

                cout << "Please enter your new surname : ";
                cin >> newSurname;

                cout << "Please enter your new password : ";
                cin >> newPassword;

                cout << "Please enter your new username : ";
                cin >> newUsername;

                account->setName(newName);
                account->setSurname(newSurname);
                account->setPassword(newPassword);
                account->setUsername(newUsername);
                Database::updateCustomerInformation(account->getId(), newName, newSurname, newPassword, newUsername);
                break;
            case 3:
                cout << "Please enter the price you are offering for this reservation : ";
                cin >> price;

                cout << "Please enter the purpose of the reservation: ";
                cin.ignore(); // Ignore any newline characters in the buffer
                getline(cin, purpose);

                cout << "Please enter the reservation date (MM/YYYY): ";
                cin >> date;

                cout << "Please enter the reservation hour: ";
                cin >> hour;

                Database::displayAllConferenceHalls();
                cout << "\n\nPlease enter the ID of the conference hall you want to select: ";
                cin >> selectedHallId;

                selectedHall = Database::getConferenceHallById(selectedHallId);
                if (selectedHall == nullptr)
                {
                    cerr << "Invalid conference hall ID. Exiting...\n";
                    return 1;
                }
                Database::createReservation(price, purpose, date, hour, account, *selectedHall);
                break;
            case 4:
                if (customerAccount != nullptr)
                {

                    Database::showCustomerReservations(*customerAccount);
                }
                else
                {
                    cout << "Conversion to Customer failed or account is not a Customer.\n";
                }
                cout << "\nPlease enter the ID of the reservation which you want to update : ";
                cin >> conferenceHallId;

                cout << "Please enter the new price you are offering for this reservation : ";
                cin >> price;

                cout << "Please enter the new purpose of the reservation: ";
                cin.ignore(); // Ignore any newline characters in the buffer
                getline(cin, purpose);

                cout << "Please enter the new reservation date (MM/YYYY): ";
                cin >> date;

                cout << "Please enter the new reservation hour: ";
                cin >> hour;

                Database::displayAllConferenceHalls();
                cout << "\n\nPlease enter the ID of the conference hall you want to select: ";
                cin >> selectedHallId;

                selectedHall = Database::getConferenceHallById(selectedHallId);
                if (selectedHall == nullptr)
                {
                    cerr << "Invalid conference hall ID. Exiting...\n";
                    return 1;
                }

                Database::updateReservation(conferenceHallId, price, purpose, date, hour, *selectedHall);
                break;

            case 5:
                Database::showCustomerReservations(*customerAccount);
                break;
            case 6:
                isLoggedIn = 0;
                break;
            }
        }
        else
        {
            cout << "\n--------- WELCOME TO CONFERENCE HALL RESERVATION SYSTEM ---------\n";

            cout << "1- Login\n";
            cout << "2- Register\n";
            cout << "3- Exit\n";

            cout << "\nSelect an option: ";
            cin >> option;

            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer

            string name;
            string surname;
            string password;
            string username;

            switch (option)
            {
            case 1:
                cout << "\nEnter your username: ";
                getline(std::cin, username);

                cout << "Enter your password: ";

                getline(std::cin, password);

                cout << "\nLogging in...\n\n";

                account = Database::login(username, password);
                if (account != nullptr)
                {
                    isLoggedIn = true;
                    break;
                }
                else
                {
                    cout << "User not found! Please try again.\n";
                }
                break;
            case 2:
                cout << "\nEnter your name: ";
                getline(cin, name);

                cout << "Enter your surname: ";
                getline(cin, surname);

                cout << "Enter your password: ";
                getline(cin, password);

                cout << "Enter your username: ";
                getline(cin, username);

                account = new Customer(Database::personId, name, surname, password, username);
                cout << "\nAccount created successfully!\n\n";
                Database::personId++;
                isLoggedIn = true;
                break;

            case 3:
                cout << "\n------------ Goodbye! ------------\n";
                return 0;

            default:
                cout << "Invalid option. Please select 1, 2, or 3.\n";
            }
        }
    }
}

void defaultInformation()
{
    // AuditoriumOwner *admin = new AuditoriumOwner(Database::personId++, "sare", "bayram", "123", "sare");
    // Customer *customer1 = new Customer(Database::personId++, "zahid", "baltaci", "123", "zahid");
    // Customer *customer2 = new Customer(Database::personId++, "rana", "gungor", "123", "rana");
    ConferenceHall conferenceHall1(Database::conferenceHallId++, "testHall1", 1000, MEDIUM_SALOON);
    ConferenceHall conferenceHall2(Database::conferenceHallId++, "testHall2", 1800, SMALL_SALOON);
    ConferenceHall conferenceHall3(Database::conferenceHallId++, "testHall3", 1500, LARGE_SALOON);
}