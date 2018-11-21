#include "prescription.h"

//==============================================================================
// Constructors
//==============================================================================
prescription::prescription()
{
    set_prescriptor();
    set_date();
}

prescription::prescription(string first_name, string last_name)
{
    set_f_name(first_name);
    set_l_name(last_name);
    set_id();
}
//==============================================================================
// Setters
//==============================================================================
void prescription::set_f_name(string nom);
{
    _first_name = nom;
}

void prescription::set_l_name(string nom);
{
    _last_name = nom;
}

void prescription::set_id()
{
    //TODO récupérer les ID existants dans les fichiers et en créer un nouveau
}

//==============================================================================
// Setters
//==============================================================================
void prescription::get_f_name(string nom);
{
    return _first_name;
}

void prescription::get_l_name(string nom);
{
    return _last_name;
}

void prescription::get_id()
{
    return id;
}

//==============================================================================
// Displayer
//==============================================================================
void prescription::display()
{
    std::cout << _first_name << '\n';
    std::cout << _last_name << '\n';
    std::cout << _id << '\n';
}
