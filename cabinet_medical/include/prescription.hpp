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

//class methods
    //setters
    void set_prescriptor(int prescriptor_id);
    void set_date();
    void append_drug(drug_struct drug);

    //getters
    int get_prescriptor();
    date get_date();
    drug_struct get_drugs();

public:
    //constructors
    prescription(doctor doc);
};


#endif
