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

void print_header()
{
    std::cout << "*************************** Welcome to Arkham Asylum ***************************" << '\n';
}

void select_patient(vector<patient> const& patient_list, int & current_patient_id)
{
    for (auto p : patient_list)
    {
        p.display();
    }
    std::cout << "Enter the chosen patient ID" << '\n';
    std::cin >> current_patient_id;
}

void select_doctor(vector<doctor> const& doctor_list, int & current_doctor_id)
{
    for (auto p : doctor_list)
    {
        p.display_doctor();
    }
    std::cout << "Enter the chosen doctor ID" << '\n';
    std::cin >> current_doctor_id;
}
