#ifndef DEF_DRUGS_STRUCT
#define DEF_DRUGS_STRUCT

#include "global.hpp"

class drug_struct
{
private:
//class variables
    string _drug_name;
    string _quantity;
    string _posology;

public:
//class methods
    //setters
    void set_name(string nom);
    void set_quantity(string quantity);
    void set_posology(string posology);

    void set_name();
    void set_quantity();
    void set_posology();

    //getters
    string get_name();
    string get_quantity();
    string get_posology();

    //constructors
    drug_struct();
    drug_struct(string drug_name, string quantity, string posology);
    //displayer
    void display();
};


#endif
