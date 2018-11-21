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
    patient pati("Ab",12, 15);
    string blood_group = pati.get_blood_group();
    std::cout << blood_group << '\n';
}
