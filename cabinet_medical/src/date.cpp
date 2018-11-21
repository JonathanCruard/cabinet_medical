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

date::date(date copy)
{
    set_year(copy.year);
    set_month(copy.month);
    set_day(copy.day);
    set_hour(copy.hour);
    set_minute(copy.minute);
}

//==============================================================================
// Setters
//==============================================================================

void date::set_year(unsigned year)
{
    this._year = year;
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
    _hour = hour;
}

void date::set_minute(unsigned minute)
{
    _minute = minute;
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
