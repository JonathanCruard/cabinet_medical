#ifndef DEF_PATIENT
#define DEF_PATIENT

#include "person.hpp"
#include "global.hpp"

class patient : public person
{
public:
//Methods
    //contructors
    patient();



private:
//Variable
    string _blood_group;
    int _security_number;
    int _telephon_number;
//Class methods
    //setters
    void set_blood_group(string blood_group);
    void set_security_number(int security_number);
    void set_telephon(int telephon_number);
    //getters
    string get_blood_group();
    int get_security_number();
    int get_telephon();

};


#endif
