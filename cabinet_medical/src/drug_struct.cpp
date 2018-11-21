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

drug_struct::drug_struct(string drug_name, float quantity, float posology)
{
    set_name(drug_name);
    set_quantity(quantity);
    set_posology(posology);
}

void drug_struct::set_name(string drug_name)
{
    this->_drug_name = drug_name;
}
void drug_struct::set_quantity(float quantity)
{
    this->_quantity = quantity;
}
void drug_struct::set_posology(float posology)
{
    this->_posology = posology;
}

void drug_struct::set_name()
{
    std::cin >> _drug_name;
}
void drug_struct::set_quantity()
{
    std::cin >> _quantity;
}
void drug_struct::set_posology()
{
    std::cin >> _posology;
}
