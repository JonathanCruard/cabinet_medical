#include "person.hpp"
#include "patient.hpp"
#include "doctor.hpp"
#include "meeting.hpp"
#include "prescription.hpp"
#include "global.hpp"
#include "date.hpp"

void patient_menu(vector<patient> & patient_list, vector<doctor> const& doctor_list, vector<meeting> & meeting_list)
{
    int current_patient_id = -1;
    int choice = 9999;
    while (choice != 0)
    {
        std::cout << "************* Welcome to Arkham Asylum *************" << '\n';
        std::cout << "Patient menu"<< '\n';
        std::cout << "1 : add new patient" << '\n';
        std::cout << "2 : choose patient" << '\n';
        if (current_patient_id != -1)
        {
            std::cout << "3 : prescript" << '\n';
            std::cout << "4 : view informations" << '\n';
        }
        std::cout << "0 : main menu" << '\n';
        std::cin >> choice;
        if (current_patient_id == -1)
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
                case 2:
                {
                    int pnum = 0;
                    for (auto p : patient_list)
                    {
                        std::cout << "Patient # : " << pnum << '\n';
                        p.display();
                    }
                    std::cout << "Enter the patient #" << '\n';
                    std::cin >> current_patient_id;
                }
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
                case 2:
                {
                    int pnum = 0;
                    for (auto p : patient_list)
                    {
                        std::cout << "Patient # : " << pnum << '\n';
                        p.display();
                    }
                    std::cout << "Enter the chosen patient #" << '\n';
                    std::cin >> current_patient_id;
                }
                break;
                case 3: patient_list[current_patient_id].add_prescription();
                break;
                case 4: patient_list[current_patient_id].display_patient();
                break;
                default:
                break;
            }
        }
    }
}

void doctor_menu(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list)
{
    int current_doctor_id = -1;
    int choice = 9999;
    while (choice != 0)
    {
        std::cout << "************* Welcome to Arkham Asylum *************" << '\n';
        std::cout << "Doctor menu"<< '\n';
        std::cout << "1 : add new doctor" << '\n';
        std::cout << "2 : choose doctor" << '\n';
        if (current_doctor_id != -1)
        {
            std::cout << "3 : view informations" << '\n';
        }
        std::cout << "0 : main menu" << '\n';
        std::cin >> choice;
        if (current_doctor_id == -1)
        {
            switch (choice)
            {
                case 0: return;
                break;
                case 1:
                {
                    doctor new_doctor;
                    doctor_list.push_back(new_doctor);
                    current_doctor_id = doctor_list.size()-1;
                }
                break;
                case 2:
                {
                    int pnum = 0;
                    for (auto p : doctor_list)
                    {
                        std::cout << "Doctor # : " << pnum << '\n';
                        p.display();
                    }
                    std::cout << "Enter the doctor #" << '\n';
                    std::cin >> current_doctor_id;
                }
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
                    doctor new_doctor;
                    doctor_list.push_back(new_doctor);
                    current_doctor_id = doctor_list.size()-1;
                }
                break;
                case 2:
                {
                    int pnum = 0;
                    for (auto p : doctor_list)
                    {
                        std::cout << "Doctor # : " << pnum << '\n';
                        p.display();
                    }
                    std::cout << "Enter the chosen doctor #" << '\n';
                    std::cin >> current_doctor_id;
                }
                break;
                case 3: doctor_list[current_doctor_id].display_doctor();
                break;
                default:
                break;
            }
        }
    }
}


void save_and_quit(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list)
{
    json_read();
}



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
            case 0: save_and_quit(patient_list, doctor_list, meeting_list);
                break;
            case 1: patient_menu(patient_list, doctor_list, meeting_list);
                break;
            case 2: doctor_menu(patient_list, doctor_list, meeting_list);
                break;
            // case 3: agenda();
                // break;
            default:
                break;
        }
    }
}
