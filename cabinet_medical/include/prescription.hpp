#ifndef DEF_PRESCRIPTION
#define DEF_PRESCRIPTION

class prescription
{
private:
//class variables
    int prescriptor;
    date prescription_date;
    drugs_struct drugs;

//class methods
    //setters
    void set_prescripteur(int doctor);
    void set_prescription_date(date date);
    void set_drugs(drugs_struct drugs);
    //getters
    int get_prescriptor();
    date get_date();
    drugs get_drugs();

};


#endif
