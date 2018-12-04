#include "patient.hpp"
#include "person.hpp"

//==============================================================================
//contructors
//==============================================================================
patient::patient() : person()
{
    set_blood_group();
    set_security_number();
    set_phone();
}

patient::patient(string blood_group, int security_number, int phone_number) : person()
{
    set_blood_group(blood_group);
    set_security_number(security_number);
    set_phone(phone_number);
}
//==============================================================================
// Setters
//==============================================================================
void patient::set_blood_group(string blood_group)
{
    this->_blood_group = blood_group;
}
void patient::set_security_number(int security_number)
{
    this->_security_number = security_number;
}
void patient::set_phone(int phone_number)
{
    this->_phone_number = phone_number;
}

void patient::set_blood_group()
{
    std::cout << "Enter your blood_group" << '\n';
    std::cin >> this->_blood_group;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_blood_group;
    }
}
void patient::set_security_number()
{
    std::cout << "Enter your security_number" << '\n';
    std::cin >> this->_security_number;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_security_number;
    }
}
void patient::set_phone()
{
    std::cout << "Enter your phone" << '\n';
    std::cin >> this->_phone_number;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_phone_number;
    }
}

void patient::add_prescription()
{
    prescription new_prescription;
    std::cout << "/* message */" << '\n';
    this->_prescription_list.push_back(new_prescription);
}

//==============================================================================
// Getters
//==============================================================================
string patient::get_blood_group()
{
    return _blood_group;
}
int patient::get_security_number()
{
    return _security_number;
}
int patient::get_phone()
{
    return _phone_number;
}

//==============================================================================
// Displayers
//==============================================================================
void patient::display_patient()
{
    display();
    std::cout << "Blood Group : " << _blood_group << '\n';
    std::cout << "Security number : " << _security_number << '\n';
    std::cout << "Phone number : " << _phone_number << '\n';
}
