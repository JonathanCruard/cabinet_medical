#include "doctor.hpp"

class doctor : public person
{
    doctor::doctor()
    {
        set_f_name("");
        set_l_name("");
        set_id();
        set_speciality("");
    }
    doctor::doctor(string speciality) person(string first_name, string last_name)
    {
        set_f_name(first_name);
        set_l_name(last_name);
        set_id();
        set_speciality(speciality);
    }

    //setters
    void doctor::set_speciality(string speciality)
    {
        string _speciality = speciality;
    }
    //getters
    string doctor::get_speciality();
    {
        return _speciality;
    }
}
