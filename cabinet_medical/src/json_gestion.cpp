#include "json_gestion.hpp"
//==============================================================================
// Constructor
//==============================================================================
json_gestion::json_gestion()
{
    this->_json_file = "./data/data.json";
}
//==============================================================================
// json_read, allows to import data from file
//==============================================================================
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
                // Initialize some structure to stock informations
                vector<prescription> prescription_list;
                // Get patient's informations
                string blood_group = patientdat[index]["blood_group"].asString();
                string fname = patientdat[index]["fname"].asString();
                string lname = patientdat[index]["lname"].asString();
                int phone_number = patientdat[index]["phone"].asInt();
                int security_number = patientdat[index]["security_number"].asInt();
                int id = patientdat[index]["id"].asInt();
                int referent_doc_id = patientdat[index]["referent_doc_id"].asInt();
                // Get all prescriptions informations
                // create a new "root" for parsing
                const Json::Value prescription_json = patientdat[index]["prescriptions"];
                // Iterate tought prescriptions (could be multiple)
                for (int index_prescription = 0; index_prescription < prescription_json.size(); index_prescription++)
                {
                    //Get prescriptor
                    int prescriptor = prescription_json[index_prescription]["prescriptor"].asInt();
                    // Get prescription's date informations and get an instance of it
                    date prescription_date = parse_date(prescription_json[index_prescription]["date"]);

                    // Initialize some structure to stock informations
                    list<drug_struct> list_drugs;
                    // Iterate tought drugs (could be multiple for one prescription)
                    for (int index_drugs = 0; index_drugs < prescription_json[index_prescription]["drugs"].size(); index_drugs++)
                    {
                        // Get prescription's drugs informations
                        string drug_name = prescription_json[index_prescription]["drugs"][index_drugs]["name"].asString();
                        string posology = prescription_json[index_prescription]["drugs"][index_drugs]["posology"].asString();
                        string quantity = prescription_json[index_prescription]["drugs"][index_drugs]["quantity"].asString();
                        // Instanciate a drug_struct object
                        drug_struct drugs_data(drug_name, quantity, posology);
                        // Add drug_struct object in list
                        list_drugs.push_back(drugs_data);
                    }
                    // Instanciate an object prescription containing prescriptor's ID, a date object, and a list of drug_struct object
                    prescription prescription_value(prescriptor, prescription_date, list_drugs);
                    // Add prescription object in list
                    prescription_list.push_back(prescription_value);
                }
                // Instanciate patient setting up informations
                patient pat(blood_group, security_number, phone_number, fname, lname, id, prescription_list, referent_doc_id);
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
                // Get doctor's informations
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
        // Read meeting informations
        Json::Value meeting_dat = root["meeting"];
        if (meeting_dat != NULL)
        {
            // Iterate over the sequence elements.
            for ( int index = 0; index < meeting_dat.size(); ++index)
            {
                // Get meeting's informations
                int id_doctor = meeting_dat[index]["id_doctor"].asInt();
                int id_patient = meeting_dat[index]["id_patient"].asInt();
                string object = meeting_dat[index]["object"].asString();
                date meeting_date = parse_date(meeting_dat[index]["date"]);
                // Instanciate meeting object
                meeting meeting_object(id_doctor, id_patient, meeting_date, object);
                // Add this instance in meeting list
                meeting_list.push_back(meeting_object);
            }
        }
    }
    else
    {
        cout << "json is not in correct format" << '\n' <<endl;
    }
}
//==============================================================================
// json_write, allows to export data to file
//==============================================================================
void json_gestion::json_write(vector<patient> & patient_list, vector<doctor> & doctor_list, vector<meeting> & meeting_list)
{
    // Open outpu file
    ofstream output_file(_json_file);
    // Initialize json value that will stock everything allowing to nest patients and doctors
    Json::Value cabinet;
    // For every patient in patient list
    for (int index_patient = 0; index_patient < patient_list.size(); index_patient++)
    {
        // Initialize some json value
        Json::Value patient_value;
        Json::Value prescription_value;
        Json::Value date_value;
        Json::Value drugs_value;
        // Initialize a vector of prescription object
        vector<prescription> prescription_list;
        // Get prescription list of current patient
        prescription_list = patient_list[index_patient].get_prescription_list();
        // Iterate tought prescriptions of current patient (He can have multiple prescriptions)
        int j = 0;
        for (auto presc : prescription_list)
        {
            // Get date object of current prescription
            date date_data = presc.get_date();
            // Get informations from this object and add them in json value to nest date
            prescription_value = construct_date_json_value(date_data);
            // Get informations of current prescriptions
            prescription_value["prescriptor"] = presc.get_prescriptor();
            // Get drug_struct object of current prescription
            list<drug_struct> drugs_list = presc.get_drugs();
            // Iterate in it (in one prescription it is possible to have multiple drugs)
            int h = 0;
            for (auto drugs_data : drugs_list)
            {
                // Get informations of current drug struct
                drugs_value["name"]= drugs_data.get_name();
                drugs_value["quantity"]= drugs_data.get_quantity();
                drugs_value["posology"]= drugs_data.get_posology();
                // Add them in json value to nest drugs
                prescription_value["drugs"][h]= drugs_value;
                h++;
            }

            // Add them in json value to nest drugs and date at the same level
            patient_value["prescriptions"][j] = prescription_value;
            j++;
        }


        // Get last patient's informations
        patient_value["blood_group"] = patient_list[index_patient].get_blood_group();
        patient_value["id"] = patient_list[index_patient].get_id();
        patient_value["fname"] = patient_list[index_patient].get_f_name();
        patient_value["lname"] = patient_list[index_patient].get_l_name();
        patient_value["security_number"] = patient_list[index_patient].get_security_number();
        patient_value["phone"] = patient_list[index_patient].get_phone();
        patient_value["referent_doc_id"] = patient_list[index_patient].get_referent_doc_ID();


        // Save patient informations in json value to nest every patients
        cabinet["patient"][index_patient] = patient_value;
    }
    // For every doctors in doctors list
    Json::Value doctor_value;
    for (int index_doctor = 0; index_doctor < doctor_list.size(); index_doctor++)
    {
        // Get doctor's informations
        doctor_value["id"] = doctor_list[index_doctor].get_id();
        doctor_value["fname"] = doctor_list[index_doctor].get_f_name();
        doctor_value["lname"] = doctor_list[index_doctor].get_l_name();
        doctor_value["speciality"] = doctor_list[index_doctor].get_speciality();
        // Save doctor informations in json value to nest every doctors
        cabinet["doctor"][index_doctor] = doctor_value;
    }
    // For every meeting in meeting list
    Json::Value meeting_value;
    for (int index_meeting = 0; index_meeting < meeting_list.size(); index_meeting++)
    {
        // Get date object of current meeting
        date date_data = meeting_list[index_meeting].get_date();
        // Get informations from this object and add them in json value to nest date
        meeting_value = construct_date_json_value(date_data);
        // Get meeting's informations
        meeting_value["id_doctor"] = meeting_list[index_meeting].get_id_doctor();
        meeting_value["id_patient"] = meeting_list[index_meeting].get_id_patient();
        meeting_value["object"] = meeting_list[index_meeting].get_object();
        // Save meeting informations in json value to nest every meeting
        cabinet["meeting"][index_meeting] = meeting_value;
    }
    // Configure the Builder
    Json::StreamWriterBuilder wbuilder;
    // Use builder to generate data set as a json and save it in a string
    string export_cabinet = Json::writeString(wbuilder, cabinet);
    // Export json string in output file
    output_file << export_cabinet << '\n';
}
//==============================================================================
// parse_date, allows to parse date informations
//==============================================================================
date json_gestion::parse_date(Json::Value data)
{
    // Get prescription's date informations
    unsigned year = data["year"].asInt();
    unsigned month = data["month"].asInt();
    unsigned day = data["day"].asInt();
    unsigned hour = data["hour"].asInt();
    // Instanciate an object date
    date date_object(year, month, day, hour);
    return date_object;
}
//==============================================================================
// construct_date_json_value, allows to construct a json value with informations from a
// date object
//==============================================================================
Json::Value json_gestion::construct_date_json_value(date date_object)
{
    // Add them in json value to nest date
    Json::Value date_value;
    date_value["date"]["year"] = date_object.get_year();
    date_value["date"]["month"] = date_object.get_month();
    date_value["date"]["day"] = date_object.get_day();
    date_value["date"]["hour"] = date_object.get_hour();
    return date_value;
}
