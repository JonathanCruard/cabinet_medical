#include "person.hpp"
#include "patient.hpp"
#include "doctor.hpp"
#include "meeting.hpp"
#include "prescription.hpp"
#include "global.hpp"
#include "date.hpp"
#include "json_gestion.hpp"
#include "main_functions.hpp"

void patient_menu(vector<patient> & patient_list, vector<doctor> const& doctor_list, vector<meeting> & meeting_list)
{
    int current_patient_id = -1;
    int choice = 9999;
    bool more = false;
    while (true)
    {
        clear_screen();
        print_header();
        if (current_patient_id != -1)
        {
            std::cout << '\n' << "      Current patient" << '\n';
            if (more)
            {
                patient_list[current_patient_id].display_patient();
                more = false;
            }
            else
            {
                patient_list[current_patient_id].display();
            }
        }
        std::cout << "********************************************************************************" << '\n';
        std::cout << '\n' << "      Patient menu"<< '\n';
        std::cout << "1 : add new patient" << '\n';
        std::cout << "2 : choose patient" << '\n';
        if (current_patient_id != -1)
        {
            std::cout << "3 : prescript" << '\n';
            std::cout << "4 : view all informations" << '\n';
        }
        std::cout << "0 : main menu" << '\n';
        std::cin >> choice;

        switch (choice)
        {
            case 0: return;
            break;
            case 1: add_patient(patient_list, current_patient_id);
            break;
            case 2: select_patient(patient_list, current_patient_id);
            break;
            if (current_patient_id != -1)
            {
                case 3: patient_list[current_patient_id].add_prescription();
                break;
                case 4: more = true;
                break;
            }
            default:
            break;
        }
    }
}

void doctor_menu(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list)
{
    int current_doctor_id = -1;
    int choice = 9999;
    bool more = false;
    while (true)
    {
        clear_screen();
        print_header();
        if (current_doctor_id != -1)
        {
            std::cout << '\n' << "      Current doctor" << '\n';
            if (more)
            {
                doctor_list[current_doctor_id].display();
                more = false;
            }
            else
            {
                doctor_list[current_doctor_id].display_doctor();
            }
        }
        std::cout << "********************************************************************************" << '\n';
        std::cout << "      Doctor menu"<< '\n';
        std::cout << "1 : add new doctor" << '\n';
        std::cout << "2 : choose doctor" << '\n';
        if (current_doctor_id != -1)
        {
            std::cout << "3 : view informations" << '\n';
        }
        std::cout << "0 : main menu" << '\n';
        std::cin >> choice;

        switch (choice)
        {
            case 0: return;
            break;
            case 1: add_doctor(doctor_list, current_doctor_id);
            break;
            case 2: select_doctor(doctor_list, current_doctor_id);
            break;
            if (current_doctor_id != -1)
            {
                case 3: more = true;
                break;
            }
            default:
            break;
        }

    }
}

void agenda_menu(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list)
{
    int choice = 9999;
    while (true)
    {
        clear_screen();
        print_header();
        std::cout << "      Agenda"<< '\n';
        std::cout << "1 : add new meeting" << '\n';
        std::cout << "2 : view meetings" << '\n';
        std::cout << "0 : main menu" << '\n';
        std::cin >> choice;

        switch (choice)
        {
            case 0: return;
            break;
            case 1: add_meeting(meeting_list, doctor_list, patient_list);
            break;
            case 2: display_meetings(meeting_list);
            break;
            default:
            break;
        }

    }
}

int main()
{
    vector<patient> patient_list;
    vector<doctor> doctor_list;
    vector<meeting> meeting_list;
    json_gestion json;
    json.json_read(patient_list, doctor_list, meeting_list);

    int choice = 9999;
    while (choice != 0)
    {
        clear_screen();
        print_header();
        std::cout << "********************************************************************************" << '\n';
        std::cout << "1 : patients menu" << '\n';
        std::cout << "2 : doctors menu" << '\n';
        std::cout << "3 : agenda" << '\n';
        std::cout << "0 : save and quit" << '\n';
        std::cin >> choice;

        switch (choice)
        {
            case 0: save_and_quit(patient_list, doctor_list, meeting_list);
                break;
            case 1: patient_menu(patient_list, doctor_list, meeting_list);
                break;
            case 2: doctor_menu(patient_list, doctor_list, meeting_list);
                break;
            case 3: agenda_menu(patient_list, doctor_list, meeting_list);
                break;
            default:
                break;
        }
    }
}
