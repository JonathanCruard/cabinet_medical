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
    set_minute();
}

date::date(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned minute)
{
    set_year(year);
    set_month(month);
    set_day(day);
    set_hour(hour);
    set_minute(minute);
}

date::date(date const& copy)
{
    set_year(copy._year);
    set_month(copy._month);
    set_day(copy._day);
    set_hour(copy._hour);
    set_minute(copy._minute);
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

void date::set_minute(unsigned minute)
{
    this->_minute = minute;
}


void date::set_year()
{
    std::cin >> _year;
}

void date::set_month()
{
    std::cin >> _month;
}

void date::set_day()
{
    std::cin >> _day;
}

void date::set_hour()
{
    std::cin >> _hour;
}

void date::set_minute()
{
    std::cin >> _minute;
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

unsigned date::get_minute()
{
    return _minute;
}
//==============================================================================
// Displayer
//==============================================================================
void date::display()
{
    std::cout << _day << '/' << _month << '/' <<  _year << '\n';
    std::cout << _hour << ':' << _minute << '\n';
}
