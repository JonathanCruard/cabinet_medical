#include "json_gestion.hpp"

json_gestion::json_gestion()
{
    this->_json_file = "./data/data.json";
}

void json_gestion::json_read(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list)
{
    // Will contains the root value after parsing.
    Json::Value root;
    // Addreader
    Json::Reader reader;
    // Open file
    ifstream ifile(_json_file);
    // Parse file and wait for result
    bool parsingSuccessful = reader.parse( ifile, root );
    // Check result of parsing before read it
    if (parsingSuccessful)
    {
        // Read patient informations
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

                int prescriptor = patientdat[index]["prescriptions"]["prescriptor"].asInt();

                unsigned year = patientdat[index]["prescriptions"]["date"]["year"].asInt();
                unsigned month = patientdat[index]["prescriptions"]["date"]["month"].asInt();
                unsigned day = patientdat[index]["prescriptions"]["date"]["day"].asInt();
                unsigned hour = patientdat[index]["prescriptions"]["date"]["hour"].asInt();

                string drug_name = patientdat[index]["prescriptions"]["drugs"]["name"].asString();
                string quantity = patientdat[index]["prescriptions"]["drugs"]["posology"].asString();
                string posology = patientdat[index]["prescriptions"]["drugs"]["quantity"].asString();

                list<drug_struct> list_drugs;
                vector<prescription> prescription_list;
                date prescription_date(year, month, day, hour);
                drug_struct drugs_data(drug_name, quantity, posology);
                list_drugs.push_back(drugs_data);
                prescription prescription_value(prescriptor, prescription_date, list_drugs);
                prescription_list.push_back(prescription_value);

                // Instanciate patient setting up informations
                patient pat(blood_group, security_number, phone_number, fname, lname, id, prescription_list);
                // Add this instance in patient list
                patient_list.push_back(pat);
            }
        }
        // Read doctor informations
        Json::Value doctordat = root["doctor"];
        if (doctordat != NULL)
        {
            // Iterate over the sequence elements.
            for ( int index = 0; index < doctordat.size(); ++index)
            {
                string fname = doctordat[index]["fname"].asString();
                string lname = doctordat[index]["lname"].asString();
                string speciality = doctordat[index]["speciality"].asString();
                int id = doctordat[index]["id"].asInt();
                // Instanciate doctor setting up informations
                doctor new_doc(speciality, fname, lname, id);
                // Add this instance in doctor list
                doctor_list.push_back(new_doc);
            }
        }
    }
    else
    {
        cout << "json is not in correct format" << endl;
    }
}
void json_gestion::json_write(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list)
{
    ofstream output_file(_json_file);
    Json::Value cabinet;
    for (int index_patient = 0; index_patient < patient_list.size(); index_patient++)
    {
        Json::Value patient_value;
        Json::Value prescription_value;
        Json::Value date_value;
        Json::Value drugs_value;
        vector<prescription> prescription_list;
        prescription_list = patient_list[index_patient].get_prescription_list();

        for (auto presc : prescription_list)
        {
            prescription_value["prescriptor"] = presc.get_prescriptor();
            date date_data = presc.get_date();
            date_value["year"] = date_data.get_year();
            date_value["month"] = date_data.get_month();
            date_value["day"] = date_data.get_day();
            date_value["hour"] = date_data.get_hour();
            prescription_value["date"] = date_value;

            list<drug_struct> drugs_list = presc.get_drugs();
            for (auto drugs_data : drugs_list)
            {
                drugs_value["name"]= drugs_data.get_name();
                drugs_value["quantity"]= drugs_data.get_quantity();
                drugs_value["posology"]= drugs_data.get_posology();
            }
            prescription_value["drugs"] = drugs_value;
        }

        patient_value["prescriptions"] = prescription_value;

        patient_value["blood_group"] = patient_list[index_patient].get_blood_group();
        patient_value["id"] = patient_list[index_patient].get_id();
        patient_value["fname"] = patient_list[index_patient].get_f_name();
        patient_value["lname"] = patient_list[index_patient].get_l_name();
        patient_value["security_number"] = patient_list[index_patient].get_security_number();
        patient_value["phone"] = patient_list[index_patient].get_phone();


        // Save patient informations
        cabinet["patient"][index_patient] = patient_value;
    }
    Json::Value doctor_value;
    for (int index_doctor = 0; index_doctor < doctor_list.size(); index_doctor++)
    {
        doctor_value["id"] = doctor_list[index_doctor].get_id();
        doctor_value["fname"] = doctor_list[index_doctor].get_f_name();
        doctor_value["lname"] = doctor_list[index_doctor].get_l_name();
        doctor_value["speciality"] = doctor_list[index_doctor].get_speciality();
        cabinet["doctor"][index_doctor] = doctor_value;
    }

    // Configure the Builder, then ...
    Json::StreamWriterBuilder wbuilder;
    std::string export_cabinet = Json::writeString(wbuilder, cabinet);
    output_file << export_cabinet << '\n';
}
