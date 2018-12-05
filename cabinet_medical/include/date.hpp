#ifndef DEF_DATE
#define DEF_DATE

#include "global.hpp"


class date
{
public:
//Variable
    unsigned _year;
    unsigned _month;
    unsigned _day;
    unsigned _hour;
//class methods
    //setters
    void set_year(unsigned year);
    void set_month(unsigned month);
    void set_day(unsigned day);
    void set_hour(unsigned hour);

    void set_year();
    void set_month();
    void set_day();
    void set_hour();
    //getters
    unsigned get_year();
    unsigned get_month();
    unsigned get_day();
    unsigned get_hour();
    //displayers
    void display();

//Methods
    //contructors
    date();
    date(unsigned year, unsigned month, unsigned day, unsigned hour);
    date(date const& copy);
};


#endif
