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
