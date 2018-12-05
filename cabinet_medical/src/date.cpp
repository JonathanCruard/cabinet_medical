#include "date.hpp"

//==============================================================================
// Constructors
//==============================================================================
date::date()
{
    set_year();
    set_month();
    set_day();
    set_hour();
}

date::date(unsigned year, unsigned month, unsigned day, unsigned hour)
{
    set_year(year);
    set_month(month);
    set_day(day);
    set_hour(hour);
}

date::date(date const& copy)
{
    set_year(copy._year);
    set_month(copy._month);
    set_day(copy._day);
    set_hour(copy._hour);
}

//==============================================================================
// Setters
//==============================================================================
void date::set_year(unsigned year)
{
    this->_year = year;
}

void date::set_month(unsigned month)
{
    this->_month = month;
}

void date::set_day(unsigned day)
{
    this->_day = day;
}

void date::set_hour(unsigned hour)
{
    this->_hour = hour;
}




void date::set_year()
{
    std::cout << "enter year (aaaa)" << '\n';
    std::cin >> this->_year;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_year;
    }
}

void date::set_month()
{
    std::cout << "enter month (mm)" << '\n';
    std::cin >> this->_month;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_month;
    }
}

void date::set_day()
{
    std::cout << "enter day (dd)" << '\n';
    std::cin >> this->_day;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_day;
    }
}

void date::set_hour()
{
    std::cout << "enter hour (hh)" << '\n';
    std::cin >> this->_hour;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_hour;
    }
}



//==============================================================================
// Getters
//==============================================================================
unsigned date::get_year()
{
    return _year;
}

unsigned date::get_month()
{
    return _month;
}

unsigned date::get_day()
{
    return _day;
}

unsigned date::get_hour()
{
    return _hour;
}

//==============================================================================
// Displayer
//==============================================================================
void date::display()
{
    std::cout << "date : " << _day << '/' << _month << '/' <<  _year << '\n';
    std::cout << "heure : " << _hour << " H" << '\n';
}
