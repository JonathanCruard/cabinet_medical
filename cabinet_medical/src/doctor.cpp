#include "doctor.hpp"

doctor::doctor(int id) : person(id)
{
    set_speciality();
}

doctor::doctor(string speciality, string first_name, string last_name, int id) : person(first_name, last_name, id)
{
    set_speciality(speciality);
}

//setters
void doctor::set_speciality(string speciality)
{
    this->_speciality = speciality;
}

void doctor::set_speciality()
{
    std::cout << "Enter the doctor speciality" << '\n';
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,this->_speciality);
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        getline(cin,this->_speciality);
    }
}

//getters
string doctor::get_speciality()
{
    return _speciality;
}

void doctor::display_doctor()
{
    display();
    std::cout << "Speciality         : " << _speciality << '\n';
}
