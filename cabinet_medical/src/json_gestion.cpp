#include "json_gestion.hpp"
#include <json/json.h>
#include <fstream>

json_gestion::json_gestion()
{
    this->_json_file = "./data/test.json";
}

void json_gestion::json_read()
{
    Json::Value root;   // will contains the root value after parsing.
    Json::Reader reader;
    ifstream ifile(_json_file);
    bool parsingSuccessful = reader.parse( ifile, root );
    std::cout << parsingSuccessful << '\n';

    if (parsingSuccessful)
    {

        const Json::Value patient = root.get("patient", "");
        if (patient.isObject()) {

            Json::Value fname = patient.get("fname", "");
            Json::Value lname = patient.get("lname", "");
            Json::Value blood_group = patient.get("blood_group", "");
            Json::Value phone_number = patient.get("phone_number", "");
            Json::Value security_number = patient.get("security_number", "");
            cout << "fname : " << fname.asString() << endl;
            cout << "lname : " << lname.asString() << endl;
            cout << "blood_group : " << blood_group.asString() << endl;
            cout << "phone_number : " << phone_number.asInt() << endl;
            cout << "security_number : " << security_number.asInt() << endl;
        } else {
            cout << "no object type" << endl;
        }
    }
    else
        {cout << "json is not correct format" << endl;}
}
void json_gestion::json_write()
{
    // will contains the root value after parsing.
    Json::Value root;
    Json::StyledWriter writer;
    // Make a new JSON document for the configuration. Preserve original comments.
    std::string outputConfig = writer.write( root );
    // You can also use streams.  This will put the contents of any JSON
    // stream at a particular sub-value, if you'd like.
    std::cin >> root["subtree"];
    // And you can write to a stream, using the StyledWriter automatically.
    std::cout << root;
}
