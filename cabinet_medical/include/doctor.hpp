#ifndef DEF_DOCTOR
#define DEF_DOCTOR

#include <string>

#include "person.hpp"


class doctor : public person
{
public:

//Methods
    doctor();

private:
//Variable
    string _speciality;
//class methods
    //setters
    void set_speciality(string speciality);
    //getters
    unsigned int get_speciality();
};


#endif
