#ifndef DEF_PERSON
#define DEF_PERSON

#include "global.hpp"


class person
{
protected:
    //class variable
    string _first_name;
    string _last_name;
    unsigned _id;

//class method
    //setters
    void set_f_name(string name);
    void set_l_name(string name);
    //void set_id();

    void set_f_name();
    void set_l_name();
    void set_id();

    //getters
    string get_f_name(string nom);
    string get_l_name(string nom);
    unsigned get_id();
    //affichage
    void display();

public:
    //constructors
    person();
    person(string first_name, string last_name);

};

#endif
