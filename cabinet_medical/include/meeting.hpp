#ifndef DEF_MEETING
#define DEF_MEETING


class meeting
{
public:


//Methods

private:
//Variable
    date _meeting_date;
    int _id_doctor;
    int _id_patient;
    string _object;
//Class methods
    //setters
    void set_id_doctor(int id_doctor);
    void set_id_patient(int id_patient);
    void set_object(string object);
    //getters
    int get_id_doctor();
    int get_id_patient();
    string get_object();
};
#endif
