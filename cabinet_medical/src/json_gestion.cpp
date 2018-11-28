#include "json_gestion.hpp"
#include <json/json.h>

json_gestion::read_file()
{
    Json::Value root;
    std::ifstream file("test.json");
    file >> root;
    std::cout << root;
}
