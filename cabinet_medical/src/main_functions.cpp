#include "person.hpp"
#include "patient.hpp"
#include "doctor.hpp"
#include "meeting.hpp"
#include "prescription.hpp"
#include "global.hpp"
#include "date.hpp"
#include "json_gestion.hpp"
#include "main_functions.hpp"

void save_and_quit(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list)
{
    json_gestion json;
    json.json_write(patient_list, doctor_list, meeting_list);
}

void clear_screen()
{
    cout << string( 100, '\n' );
}

void print_header()
{
    std::cout << "*************************** Welcome to Arkham Asylum ***************************" << '\n';
}

void display_patient_list(vector<patient> const& patient_list)
{
    for (auto p : patient_list)
    {
        p.display();
    }
}

void display_doctor_list(vector<doctor> const& doctor_list)
{
    for (auto p : doctor_list)
    {
        p.display();
    }
}

void select_patient(vector<patient> const& patient_list, int & current_patient_id)
{
    current_patient_id = -1;
    bool first = true;
    while ((current_patient_id < 0) || (current_patient_id > patient_list.size()-1))
    {
        display_patient_list(patient_list);
        if (first)
        {
            first = false;
        }
        else
        {
            std::cout << "Unknown ID given" << '\n';
        }
        std::cout << "Enter the chosen patient ID" << '\n';
        std::cin >> current_patient_id;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input, try again" << '\n';
            std::cin >> current_patient_id;
        }
    }
}

void select_doctor(vector<doctor> const& doctor_list, int & current_doctor_id)
{
    current_doctor_id = -1;
    bool first = true;
    while ((current_doctor_id < 0) || (current_doctor_id > doctor_list.size()-1))
    {
        display_doctor_list(doctor_list);
        if (first)
        {
            first = false;
        }
        else
        {
            std::cout << "Unknown ID given" << '\n';
        }
        std::cout << "Enter the chosen doctor ID" << '\n';
        std::cin >> current_doctor_id;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid input, try again" << '\n';
            std::cin >> current_doctor_id;
        }
    }
}

void add_doctor(vector<doctor> & doctor_list, int & current_doctor_id)
{
    doctor new_doctor(doctor_list.size());
    doctor_list.push_back(new_doctor);
    current_doctor_id = doctor_list.size()-1;
}

void add_patient(vector<patient> & patient_list, int & current_patient_id)
{
    patient new_patient(patient_list.size());
    patient_list.push_back(new_patient);
    current_patient_id = patient_list.size()-1;
}

void add_meeting(vector<meeting> & meeting_list, vector<doctor> & doctor_list, vector<patient> & patient_list)
{
    int doc_ID;
    int pat_ID;
    select_doctor(doctor_list, doc_ID);
    select_patient(patient_list, pat_ID);
    meeting new_meeting(doc_ID, pat_ID);
    meeting_list.push_back(new_meeting);
}

void display_meetings(vector<meeting> const& meeting_list)
{
    for (auto p : meeting_list)
    {
        p.display();
    }
}
