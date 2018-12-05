#ifndef DEF_JSON_GESTION
#define DEF_JSON_GESTION

#include <json/json.h>
#include <fstream>
#include "date.hpp"
#include "doctor.hpp"
#include "global.hpp"
#include "meeting.hpp"
#include "patient.hpp"
#include "person.hpp"
#include "prescription.hpp"


class json_gestion
{
public:

    json_gestion();
    void json_read(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list);
    void json_write(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list);
    date parse_date(Json::Value patientdat);
    Json::Value construct_date_json_value(date date_object);

    //Variable
        string _json_file;
};

#endif
