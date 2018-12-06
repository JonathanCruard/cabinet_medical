#ifndef DEF_DOCTOR
#define DEF_DOCTOR

#include <string>

#include "person.hpp"


class doctor : public person
{
public:

//Methods
    //contructors
    doctor(int id);
    doctor(string speciality, string first_name, string last_name, int id);
    //displayer
    void display_doctor();
    //getters
    string get_speciality();


private:
//Class variable
    string _speciality;
//class methods
    //setters
    void set_speciality(string speciality);
    void set_speciality();
};


#endif
