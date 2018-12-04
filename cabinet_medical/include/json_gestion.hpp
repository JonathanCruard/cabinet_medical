#ifndef DEF_JSON_GESTION
#define DEF_JSON_GESTION

#include <json/json.h>

#include "global.hpp"


class json_gestion
{
public:

    json_gestion();
    void json_read();
    void json_write();

    //Variable
        string _json_file;
};

#endif
