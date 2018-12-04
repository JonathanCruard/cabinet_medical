#ifndef DEF_JSON_GESTION
#define DEF_JSON_GESTION

#include <json/json.h>
#include "person.hpp"
#include "patient.hpp"
#include "doctor.hpp"
#include "meeting.hpp"
#include "global.hpp"


class json_gestion
{
public:

    json_gestion();
    void json_read(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list);
    void json_write(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list);

    //Variable
        string _json_file;
};

#endif
