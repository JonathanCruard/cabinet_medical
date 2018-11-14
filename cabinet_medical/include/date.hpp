#ifndef DEF_DATE
#define DEF_DATE

#include "global.hpp"


class date
{
public:
//Variable
    unsigned int _year;
    unsigned int _month;
    unsigned int _day;
//class methods
    //setters
    void set_year(int year);
    void set_month(int month);
    void set_day(int day);
    //getters
    unsigned int get_year();
    unsigned int get_month();
    unsigned int get_day();

//Methods
    //contructors
    date();
    date(unsigned int year, unsigned int month, unsigned int day);
};


#endif
