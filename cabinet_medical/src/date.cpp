#include "date.hpp"

//==============================================================================
// Constructors
//==============================================================================
date::date()
{
    set_year(0);
    set_month(0);
    set_day(0);
    set_hour(0);
    set_minute(0);
}

date::date(unsigned year, unsigned month, unsigned day, unsigned hour, unsigned minute)
{
    set_year(year);
    set_month(month);
    set_day(day);
    set_hour(hour);
    set_minute(minute);
}

//==============================================================================
// Setters
//==============================================================================

void date::set_year(unsigned year)
{
    _year = year;
}

void date::set_month(unsigned month)
{
    _month = month;
}

void date::set_day(unsigned day)
{
    _day = day;
}

void date::set_hour(unsigned hour)
{
    return _hour;
}

void date::set_minute(unsigned minute)
{
    return _minute;
}

//==============================================================================
// Getters
//==============================================================================

void date::get_year()
{
    return _year;
}

void date::get_month()
{
    return _month;
}

void date::get_day()
{
    return _day;
}

void date::get_hour()
{
    return _hour;
}

void date::get_day()
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
