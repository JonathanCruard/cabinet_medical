#include "json_gestion.hpp"

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
        Json::Value patientdat = root["patient"];
        if (patientdat != NULL)
        {
            // Iterate over the sequence elements.
            for ( int index = 0; index < patientdat.size(); ++index)
            {
                string blood_group = patientdat[index]["blood_group"].asString();
                string fname = patientdat[index]["fname"].asString();
                string lname = patientdat[index]["lname"].asString();
                int phone_number = patientdat[index]["phone_number"].asInt();
                int security_number = patientdat[index]["security_number"].asInt();
                int id = patientdat[index]["id"].asInt();

                patient test(blood_group, security_number, phone_number, fname, lname, id);

                patient_list.push_back(test);
                //
                // patient_list.push_back(pat);
            }
        }
        Json::Value doctordat = root["doctor"];
        if (doctordat != NULL) {
            // Iterate over the sequence elements.
            for ( int index = 0; index < doctordat.size(); ++index)
            {
                string fname = doctordat[index]["fname"].asString();
                string lname = doctordat[index]["lname"].asString();
                string speciality = doctordat[index]["speciality"].asString();
                int id = doctordat[index]["id"].asInt();

                doctor new_doc(speciality, fname, lname, id);
                doctor_list.push_back(new_doc);
            }
        }
    }
    else
        {cout << "json is not in correct format" << endl;}
}
void json_gestion::json_write(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list)
{
    ofstream output_file(_json_file);
    Json::Value patient;
    Json::Value patient_value;
    for (int index_patient = 0; index_patient < patient_list.size(); index_patient++)
    {
        patient_value["blood_group"] = patient_list[index_patient].get_blood_group();
        patient_value["id"] = patient_list[index_patient].get_id();
        patient_value["fname"] = patient_list[index_patient].get_f_name();
        patient_value["lname"] = patient_list[index_patient].get_l_name();
        patient_value["security_number"] = patient_list[index_patient].get_security_number();
        patient_value["phone"] = patient_list[index_patient].get_phone();
        patient["patient"][index_patient] = patient_value;
    }

    Json::Value doctor;
    Json::Value doctor_value;
    for (int index_doctor = 0; index_doctor < doctor_list.size(); index_doctor++)
    {
        doctor_value["id"] = doctor_list[index_doctor].get_id();
        doctor_value["fname"] = doctor_list[index_doctor].get_f_name();
        doctor_value["lname"] = doctor_list[index_doctor].get_l_name();
        doctor_value["speciality"] = doctor_list[index_doctor].get_speciality();
        doctor["doctor"][index_doctor] = doctor_value;
    }

    // Configure the Builder, then ...
    Json::StreamWriterBuilder wbuilder;
    std::string export_patient = Json::writeString(wbuilder, patient);
    output_file << export_patient << '\n';
    std::string export_doctor = Json::writeString(wbuilder, doctor);
    output_file << export_doctor << '\n';
}
