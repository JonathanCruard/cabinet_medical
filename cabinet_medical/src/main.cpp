#include "person.hpp"
#include "patient.hpp"
#include "doctor.hpp"
#include "meeting.hpp"
#include "prescription.hpp"
#include "global.hpp"
#include "date.hpp"


int main()
{
    vector<patient> patient_list;
    vector<doctor> doctor_list;
    vector<meeting> meeting_list;
    int choice = 9999;
    while (choice != 0)
    {
        std::cout << "************* Welcome to Arkham Asylum *************" << '\n' << "To control this program please select one of those possibilities:"<< '\n';
        std::cout << "1 : patients menu" << '\n';
        std::cout << "2 : doctors menu" << '\n';
        std::cout << "3 : agenda" << '\n';
        std::cout << "0 : save and quit" << '\n';
        std::cin >> choice;

        switch (choice)
        {
            case 0: save_and_quit();
                break;
            case 1: patient_menu(patient_list, doctor_list, meeting_list);
                break;
            case 2: doctor_menu(patient_list, doctor_list, meeting_list);
                break;
            case 3: agenda();
                break;
            default:
                break;
        }
    }
}

void patient_menu(vector<patient> & patient_list, vector<doctor> const& doctor_list, vector<meeting> & meeting_list)
{
    int current_patient_id = -1
    int choice = 9999;
    while (choice != 0)
    {
        std::cout << "************* Welcome to Arkham Asylum *************" << '\n';
        std::cout << "Patient menu"<< '\n';
        std::cout << "1 : add new patient" << '\n';
        std::cout << "2 : choose patient" << '\n';
        if (current_patient_id != -1)
        {
            std::cout << "3 : schedule meeting" << '\n';
            std::cout << "4 : prescript" << '\n';
            std::cout << "5 : view informations" << '\n';
        }
        std::cout << "0 : main menu" << '\n';
        std::cin >> choice;
        if (current_patient_id == -1)
        {
            switch (choice)
            {
                case 0: return;
                break;
                case 1: add_patient(vector<patient> & patient_list);
                break;
                case 2: current_patient_id = choose_patient(vector<patient> & patient_list);
                break;
                default:
                break;
            }
        }
        else
        {
            switch (choice)
            {
                case 0: return;
                break;
                case 1:
                {
                    patient new_patient;
                    patient_list.push_back(new_patient);
                    current_patient_id = patient_list.size()-1;
                }
                break;
                case 2: current_patient_id = choose_patient(patient_list);
                break;
                case 3: schedule_meeting(current_patient_id, doctor_list, meeting_list);
                break;
                case 4: patient_list[current_patient_id].add_prescription();
                break;
                case 5: patient_list[current_patient_id].display();
                break;
                default:
                break;
            }
        }
    }
}
