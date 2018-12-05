#ifndef DEF_MEETING
#define DEF_MEETING

#include "global.hpp"
#include "date.hpp"
#include "patient.hpp"
#include "doctor.hpp"

class meeting
{
public:
//Methods
    //contructors
    meeting(int ID_doc, int ID_pat);
    meeting(int ID_doc, int ID_pat, date meet_date, string object);
    //getters
    unsigned get_id_doctor();
    unsigned get_id_patient();
    string get_object();
    date get_date();

//Methods
    void display();
private:
//Variable
    date _meeting_date;
    int _id_doctor;
    int _id_patient;
    string _object;
//Class methods
    //setters
    void set_id_doctor(unsigned id_doctor);
    void set_id_patient(unsigned id_patient);
    void set_meeting_date();
    void set_meeting_date(date new_date);
    void set_object();
    void set_object(string object);

};
#endif
