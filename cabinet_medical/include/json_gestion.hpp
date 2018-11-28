#ifndef DEF_PATIENT
#define DEF_PATIENT

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
