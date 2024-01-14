Person::Person(int _id, const string &_name, const string &_surname, const string &_password, const string &_username)
    : id(_id), name(_name), surname(_surname), password(_password), username(_username)
{
    Database::person.push_back(this);
}