#include "date.hpp"

//==============================================================================
// Constructors
//==============================================================================
date::date()
{
    set_year(0);
    set_month(0);
    set_day(0);
}
date::date(unsigned int year, unsigned int month, unsigned int day)
{
    set_year(year);
    set_month(month);
    set_day(day);
}

//==============================================================================
// Setters
//==============================================================================

date::set_year(unsigned int year)
{
    _year = year;
}

date::set_month(unsigned int month)
{
    _month = month;
}

date::set_day(unsigned int day)
{
    _day = day;
}


//==============================================================================
// Getters
//==============================================================================

date::get_year()
{
    return _year;
}

date::get_month()
{
    return _month;
}

date::get_day()
{
    return _day;
}
