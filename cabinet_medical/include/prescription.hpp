#ifndef DEF_PRESCRIPTION
#define DEF_PRESCRIPTION

class prescription
{
private:
//class variables
    int _prescriptor;
    date _prescription_date;
    list<drug_struct> _drugs;

//class methods
    //setters
    void set_prescripteur(int doctor);
    void set_date(date date);
    void append_drug(drug_struct drug);
    //getters
    int get_prescriptor();
    date get_date();
    drugs get_drugs();

public:
    //constructors
    prescription();
    prescription(int prescriptor, date date);
    prescription(int prescriptor, date date, list<drug_struct>);
    //TODO à revoir
};


#endif
