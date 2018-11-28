#include "drug_struct.hpp"


//==============================================================================
// Constructors
//==============================================================================
drug_struct::drug_struct()
{
    set_name();
    set_quantity();
    set_posology();
}

drug_struct::drug_struct(string drug_name, string quantity, string posology)
{
    set_name(drug_name);
    set_quantity(quantity);
    set_posology(posology);
}

//==============================================================================
// Setters
//==============================================================================
void drug_struct::set_name(string drug_name)
{
    this->_drug_name = drug_name;
}
void drug_struct::set_quantity(string quantity)
{
    this->_quantity = quantity;
}
void drug_struct::set_posology(string posology)
{
    this->_posology = posology;
}

void drug_struct::set_name()
{
    std::cout << "Enter drug name" << '\n';
    std::cin >> this->_drug_name;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_drug_name;
    }
}
void drug_struct::set_quantity()
{
    std::cout << "Enter quantity" << '\n';
    std::cin >> this->_quantity;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_quantity;
    }
}
void drug_struct::set_posology()
{
    std::cout << "Enter posology" << '\n';
    std::cin >> this->_posology;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Invalid input, try again" << endl;
        std::cin >> this->_posology;
    }
}

//==============================================================================
// Getters
//==============================================================================
string drug_struct::get_name()
{
    return _drug_name;
}
string drug_struct::get_quantity()
{
    return _quantity;
}
string drug_struct::get_posology()
{
    return _posology;
}

//==============================================================================
// Displayers
//==============================================================================
void drug_struct::display()
{
    std::cout << "Drug name : " << _drug_name << '\n';
    std::cout << "Quantity : " << _quantity << '\n';
    std::cout << "Posology : " << _posology << '\n';
}
