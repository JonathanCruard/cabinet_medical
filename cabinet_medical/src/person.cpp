#include "person.hpp"

//==============================================================================
// Constructors
//==============================================================================
person::person()
{
    set_f_name();
    set_l_name();
    set_id();
}

person::person(string first_name, string last_name)
{
    set_f_name(first_name);
    set_l_name(last_name);
    set_id();
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

void person::set_id()
{
    //TODO récupérer les ID existants dans les fichiers et en créer un nouveau
}

//==============================================================================
// Setters
//==============================================================================
string person::get_f_name(string nom)
{
    return _first_name;
}

string person::get_l_name(string nom)
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
    std::cout << _first_name << '\n';
    std::cout << _last_name << '\n';
    std::cout << _id << '\n';
}
