#ifndef DEF_PERSON
#define DEF_PERSON

#include "global.hpp"


class person
{
protected:
    //class variable
    string first_name;
    string last_name;

//class method
    //setters
    void set_f_name(string name);
    void set_l_name(string name);

    //getters
    string get_f_name();
    string get_l_name();

    //affichage
    void display();

};


#endif
