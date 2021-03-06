#ifndef DEF_PRESCRIPTION
#define DEF_PRESCRIPTION

#include "global.hpp"
#include "drug_struct.hpp"
#include "date.hpp"
#include "doctor.hpp"

class prescription
{
private:
//class variables
    int _prescriptor;
    date _prescription_date;
    list<drug_struct> _drugs;


public:
//class methods
    //setters
    void set_prescriptor();
    void set_prescriptor(int prescriptor);
    void set_date();
    void append_drug();
    //getters
    int get_prescriptor();
    date get_date();
    list<drug_struct> get_drugs();
    //displayer
    void display();
    //constructors
    prescription();
    prescription(int prescriptor, date prescription_date, list<drug_struct> drugs);
};


#endif
