#include "meeting.hpp"

//==============================================================================
// Constructors
//==============================================================================
meeting::meeting(doctor doc, patient sickguy)
{
    set_meeting_date();
    set_id_doctor(doc.get_id());
    set_id_patient(sickguy.get_id());
    set_object();
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

void meeting::set_object()
{
    std::cout << "What is meeting's object?" << '\n';
    std::cin >> this->_object;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_object;
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
