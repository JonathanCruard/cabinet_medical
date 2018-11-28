#include "doctor.hpp"

doctor::doctor() : person()
{
    set_speciality();
}

doctor::doctor(string speciality) : person()
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
    std::cin >> this->_speciality;
}

//getters
string doctor::get_speciality()
{
    return _speciality;
}

void doctor::display()
{
    std::cout << "First Name  : " << _first_name << '\n';
    std::cout << "Last Name  : " << _last_name << '\n';
    std::cout << "ID  : " << _id << '\n';
    std::cout << "Speciality : " << _speciality << '\n';
}
