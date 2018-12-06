#include "meeting.hpp"

//==============================================================================
// Constructors
//==============================================================================
meeting::meeting(int ID_doc, int ID_pat)
{
    set_id_doctor(ID_doc);
    set_id_patient(ID_pat);
    set_object();
}

meeting::meeting(int ID_doc, int ID_pat, date meet_date, string object) : _meeting_date(meet_date)
{
    set_object(object);
    set_id_doctor(ID_doc);
    set_id_patient(ID_pat);
    set_meeting_date(meet_date);
}

//==============================================================================
// Setters
//==============================================================================
void meeting::set_id_doctor(unsigned id_doc)
{
    this->_id_doctor = id_doc;
}

void meeting::set_id_patient(unsigned id_patient)
{
    this->_id_patient = id_patient;
}

void meeting::set_meeting_date()
{
    date _meeting_date;
}

void meeting::set_meeting_date(date new_date)
{
    this->_meeting_date = new_date;
}

void meeting::set_object(string object)
{
    this->_object = object;
}

void meeting::set_object()
{
    std::cout << "What is meeting object?" << '\n';
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin,this->_object);
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        getline(cin,this->_object);
    }
}


//==============================================================================
// Getters
//==============================================================================

unsigned meeting::get_id_doctor()
{
    return _id_doctor;
}

unsigned meeting::get_id_patient()
{
    return _id_patient;
}

string meeting::get_object()
{
    return _object;
}
date meeting::get_date()
{
    return _meeting_date;
}

//==============================================================================
// Displayer
//==============================================================================

void meeting::display()
{
    std::cout << "##############################" << '\n';
    _meeting_date.display();
    std::cout << "Doctor ID : " << _id_doctor << '\n';
    std::cout << "Patient ID : " << _id_patient << '\n';
    std::cout << "Object of the visit :" << '\n' << "   " << _object << '\n';

}
