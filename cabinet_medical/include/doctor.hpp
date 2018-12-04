#ifndef DEF_DOCTOR
#define DEF_DOCTOR

#include <string>

#include "person.hpp"


class doctor : public person
{
public:

//Methods
    //contructors
    doctor();
    doctor(string speciality);
    //displayer
    void display_doctor();
    //getters
    string get_speciality();


private:
//Variable
    string _speciality;
//class methods
    //setters
    void set_speciality(string speciality);
    void set_speciality();
};


#endif
