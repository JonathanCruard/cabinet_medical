#ifndef DEF_MAIN_FUNCTIONS_HPP
#define DEF_MAIN_FUNCTIONS_HPP

#include "person.hpp"
#include "patient.hpp"
#include "doctor.hpp"
#include "meeting.hpp"
#include "prescription.hpp"
#include "global.hpp"
#include "date.hpp"
#include "json_gestion.hpp"


void save_and_quit(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list);

void print_header();
void clear_screen();

void display_patient_list(vector<patient> const& patient_list);

void display_doctor_list(vector<doctor> const& doctor_list);

void select_patient(vector<patient> const& patient_list, int & current_patient_id);

void select_doctor(vector<doctor> const& doctor_list, int & current_doctor_id);

void add_doctor(vector<doctor> & doctor_list, int & current_doctor_id);

void add_patient(vector<patient> & patient_list, int & current_patient_id);

void add_meeting(vector<meeting> & meeting_list, vector<doctor> & doctor_list, vector<patient> & patient_list);

void display_meetings(vector<meeting> const& meeting_list);

#endif
