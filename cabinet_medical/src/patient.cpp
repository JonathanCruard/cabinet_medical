#include "patient.hpp"

//==============================================================================
//contructors
//==============================================================================
patient::patient(int id) : person(id)
{
    set_referent_doc_ID();
    set_blood_group();
    set_security_number();
    set_phone();
}

patient::patient(string blood_group, int security_number, int phone_number, string first_name, string last_name, int id, int referent_doc_ID) : person(first_name, last_name, id)
{
    set_referent_doc_ID(referent_doc_ID);
    set_blood_group(blood_group);
    set_security_number(security_number);
    set_phone(phone_number);
}

patient::patient(string blood_group, int security_number, int phone_number, string first_name, string last_name, int id, vector<prescription> prescripts, int referent_doc_ID) : person(first_name, last_name, id)
{
    set_referent_doc_ID(referent_doc_ID);
    set_blood_group(blood_group);
    set_security_number(security_number);
    set_phone(phone_number);
    this->_prescription_list = prescripts;
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

void patient::set_referent_doc_ID(int referent_doc_ID)
{
    this->_referent_doc_ID = referent_doc_ID;
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
    std::cout << "Enter phone number" << '\n';
    std::cin >> this->_phone_number;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_phone_number;
    }
}

void patient::set_referent_doc_ID()
{
    std::cout << "Please enter the ID of the referent doctor" << '\n';
    std::cin >> this->_referent_doc_ID;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_referent_doc_ID;
    }
}


void patient::add_prescription()
{
    std::cout << "Enter prescription date" << '\n';
    prescription new_prescription;
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
vector<prescription> patient::get_prescription_list()
{
    return _prescription_list;
}
int patient::get_referent_doc_ID()
{
    return _referent_doc_ID;
}

//==============================================================================
// Displayers
//==============================================================================
void patient::display_patient()
{
    display();
    std::cout << "Referent doctor ID : " << _referent_doc_ID << '\n';
    std::cout << "Blood Group : " << _blood_group << '\n';
    std::cout << "Security number : " << _security_number << '\n';
    std::cout << "Phone number : " << _phone_number << '\n';
}

void patient::display_prescriptions()
{
    display_patient();
    for (auto presc : _prescription_list)
    {
        std::cout << "*******" << '\n';
        presc.display();
    }
}
