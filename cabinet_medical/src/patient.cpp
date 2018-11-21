#include "patient.hpp"
#include "person.hpp"

class patient : public person
{
    //==========================================================================
    //contructors
    //==========================================================================
    patient::patient()
    {
        set_f_name("");
        set_l_name("");
        set_id();
        set_blood_group("");
        set_security_number("");
        set_phone("");
    }
    patient::patient(string blood_group, int security_number, int phone_number) : person(string first_name, string last_name)
    {
        set_f_name("");
        set_l_name("");
        set_id();
        set_blood_group(string blood_group);
        set_security_number(int security_number);
        set_phone(int phone_number);
    }
    //==========================================================================
    // Setters
    //==========================================================================
    void patient::set_blood_group(string blood_group)
    {
        _blood_group = blood_group;
    }
    void patient::set_security_number(int security_number)
    {
        _security_number = security_number;
    }
    void patient::set_phone(int phone_number)
    {
        _phone_number = phone_number;
    }

    //==========================================================================
    // Getters
    //==========================================================================
    string patient::get_blood_group()
    {
        return _blood_group;
    }
    int patient::get_security_number()
    {
        return _security_number;
    }
    int patient::get_phone()
    {
        return _phone_number;
    }

}
