#ifndef DEF_PATIENT
#define DEF_PATIENT

#include "person.hpp"
#include "global.hpp"
#include "date.hpp"

class patient : public person
{
public:
//Methods
    //contructors
    patient();
    patient(string blood_group, int security_number, int telephon_number);


    //getters
    string get_blood_group();
    int get_security_number();
    int get_phone();


private:
//Variable
    string _blood_group;
    int _security_number;
    int _phone_number;
//Class methods
    //setters
    void set_blood_group(string blood_group);
    void set_security_number(int security_number);
    void set_phone(int phone_number);

    void set_blood_group();
    void set_security_number();
    void set_phone();


};


#endif
