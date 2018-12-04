#include "json_gestion.hpp"
#include "person.hpp"
#include "patient.hpp"
#include "doctor.hpp"
#include "meeting.hpp"
#include <json/json.h>
#include <fstream>

json_gestion::json_gestion()
{
    this->_json_file = "./data/data.json";
}

void json_gestion::json_read(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list)
{
    Json::Value root;   // will contains the root value after parsing.
    Json::Reader reader;
    ifstream ifile(_json_file);
    bool parsingSuccessful = reader.parse( ifile, root );

    if (parsingSuccessful)
    {
        Json::Value patient = root["patient"];
        if (patient != NULL)
        {
            // Iterate over the sequence elements.
            for ( int index = 0; index < patient.size(); ++index)
            {
                Json::Value blood_group = patient[index]["blood_group"];
                Json::Value fname = patient[index]["fname"];
                Json::Value lname = patient[index]["lname"];
                Json::Value phone_number = patient[index]["phone_number"];
                Json::Value security_number = patient[index]["security_number"];
                patient pat(blood_group.asString(), security_number.asInt(), phone_number.asInt()) (fname.asString(), lname.asString())
                patient_list.push_back(pat);
            }
        }
        Json::Value doctor = root["doctor"];
        if (doctor != NULL) {
            // Iterate over the sequence elements.
            for ( int index = 0; index < doctor.size(); ++index)
            {
                Json::Value fname = doctor[index]["fname"];
                Json::Value lname = doctor[index]["lname"];
                Json::Value speciality = doctor[index]["speciality"];
                cout << "fname : " << fname.asString() << endl;
                cout << "lname : " << lname.asString() << endl;
                cout << "speciality : " << speciality.asString() << endl;
            }
        }
    }
    else
        {cout << "json is not in correct format" << endl;}
}
void json_gestion::json_write(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list)
{
    Json::Value patient;
    Json::Value patient_value;
    for (size_t index_patient = 0; index_patient < patient_list.size(); index_patient++)
    {
        patient_value["blood_group"] = patient_list[index_patient].get_blood_group();
        patient_value["id"] = patient_list[index_patient].get_id();
        patient_value["fname"] = patient_list[index_patient].get_f_name();
        patient_value["lname"] = patient_list[index_patient].get_l_name();
        patient_value["security_number"] = patient_list[index_patient].get_security_number();
        patient_value["phone"] = patient_list[index_patient].get_phone();
    }
    std::cout << patient_value << '\n';
    // Configure the Builder, then ...
    Json::StreamWriterBuilder wbuilder;

    // std::string out1 = Json::writeString(wbuilder, val);
}
