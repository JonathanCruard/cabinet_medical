#include <iostream>
using namespace std;

#include "person.hpp"
#include "patient.hpp"
#include "doctor.hpp"
#include "meeting.hpp"
#include "prescription.hpp"
#include "global.hpp"
#include "date.hpp"

int main()
{
    int choice = 1;
    while (choice != 0) {
        std::cout << "*************Welcome to Arkham Asylum:*************" << '\n' << "To control this program please selct one of those possibilities:"<< '\n';
        std::cout << "1: For add new patients" << '\n' << "1: For add new doctors"<< '\n';
        std::cin >> choice;
        switch (choice) {
            case 1:
                break;
            case 2:
            default:
                break;
        }
    }
    patient pati("Ab",12, 15);
    string blood_group = pati.get_blood_group();
    std::cout << blood_group << '\n';
}
