#include "person.hpp"

//==============================================================================
// Constructors
//==============================================================================
person::person(int id)
{
    set_f_name();
    set_l_name();
    set_id(id);
}

person::person(string first_name, string last_name, int id)
{
    set_f_name(first_name);
    set_l_name(last_name);
    set_id(id);

}
//==============================================================================
// Setters
//==============================================================================
void person::set_f_name(string nom)
{
    this->_first_name = nom;
}

void person::set_l_name(string nom)
{
    this->_last_name = nom;
}

void person::set_id(int id) {
    this->_id = id;
}

void person::set_f_name()
{
    std::cout << "What is first name? " << '\n';
    cin.ignore();
    getline(cin,this->_first_name);
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        getline(cin,this->_first_name);
    }
}
void person::set_l_name()
{
    std::cout << "What is last name? " << '\n';
    cin.ignore();
    getline(cin,this->_last_name);
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        getline(cin,this->_last_name);
    }
}

//==============================================================================
// Getters
//==============================================================================
string person::get_f_name()
{
    return _first_name;
}

string person::get_l_name()
{
    return _last_name;
}

unsigned person::get_id()
{
    return _id;
}

//==============================================================================
// Displayer
//==============================================================================
void person::display()
{
    std::cout << "********************************************************************************" << '\n';
    std::cout << "First Name         : " << _first_name << '\n';
    std::cout << "Last Name          : " << _last_name << '\n';
    std::cout << "ID                 : " << _id << '\n';
}
