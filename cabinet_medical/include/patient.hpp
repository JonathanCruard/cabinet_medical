#ifndef DEF_PATIENT
#define DEF_PATIENT

#include "person.hpp"
#include "global.hpp"
#include "date.hpp"
#include "prescription.hpp"

class patient : public person
{
public:
//Methods
    //contructors
    patient(int id);
    patient(string blood_group, int security_number, int phone_number, string first_name, string last_name, int id, int referent_doc_ID);
    patient(string blood_group, int security_number, int phone_number, string first_name, string last_name, int id, vector<prescription>, int referent_doc_ID);

    //setters
    void set_blood_group(string blood_group);
    void set_security_number(int security_number);
    void set_phone(int phone_number);
    void set_referent_doc_ID(int referent_doc_ID);

    void set_blood_group();
    void set_security_number();
    void set_phone();
    void set_referent_doc_ID();

    void add_prescription();


    //getters
    string get_blood_group();
    int get_security_number();
    int get_phone();
    vector<prescription> get_prescription_list();
    int get_referent_doc_ID();

    //displayer
    void display_patient();
    void display_prescriptions();


private:
//Variable
    string _blood_group;
    int _security_number;
    int _phone_number;
    int _referent_doc_ID;
    vector<prescription> _prescription_list;
};


#endif
