#include "meeting.h"

//==============================================================================
// Constructors
//==============================================================================
meeting::meeting()
{
    _meeting_date = meeting_date;
    set_id_doctor(42);
    set_id_patient(42);
    set_object(" ");
}
meeting::meeting(date meeting_date, int id_doctor, int id_patient, string object)
{
    _meeting_date = meeting_date;
    set_id_doctor(id_doctor);
    set_id_patient(id_patient);
    set_object(object);
}

//==============================================================================
// Setters
//==============================================================================

meeting::set_id_doctor(int id_doctor)
{
    _id_doctor = id_doctor;
}

meeting::set_id_patient(int id_patient)
{
    _id_patient = id_patient;
}

meeting::set_object(string object)
{
    _object = object;
}


//==============================================================================
// Getters
//==============================================================================

meeting::get_id_doctor()
{
    return _id_doctor;
}

meeting::get_id_patient()
{
    return _id_patient;
}

meeting::get_object(string object)
{
    return _object;
}
