#ifndef DEF_DRUGS_STRUCT
#define DEF_DRUGS_STRUCT

#include "global.hpp"

class drug_struct
{
private:
//class variables
    string _drug_name;
    float _quantity;
    float _posology;
//class methods
    //setters
    void set_name(string nom);
    void set_quantity(float quant);
    void set_posology(float posology);
    //getters
    string get_name();
    float get_quantity();
    float get_posology();

public:
    //constructors
    drug_struct();
    drug_struct(string drug_name, float quantity, float posology);


};


#endif
