#include "person.h"

//==============================================================================
// Constructors
//==============================================================================
person::person()
{
    set_f_name("");
    set_l_name("");
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
void person::set_f_name(string nom);
{
    _first_name = nom;
}

void person::set_l_name(string nom);
{
    _last_name = nom;
}

void person::set_id()
{
    //TODO récupérer les ID existants dans les fichiers et en créer un nouveau
}

//==============================================================================
// Setters
//==============================================================================
void person::get_f_name(string nom);
{
    return _first_name;
}

void person::get_l_name(string nom);
{
    return _last_name;
}

void person::get_id()
{
    return id;
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
