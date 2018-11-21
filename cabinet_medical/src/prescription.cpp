#include "prescription.hpp"

//==============================================================================
// Constructors
//==============================================================================
prescription::prescription(doctor doc)
{
    set_prescriptor(doc.get_id());
    set_date();
}

//==============================================================================
// Setters
//==============================================================================
void prescription::set_prescriptor(int prescriptor_id)
{
    this->_prescriptor = prescriptor_id;
}

void prescription::set_date()
{
    date _prescription_date;
}

void append_drug(drug_struct drug);
{

}
//==============================================================================
// Displayer
//==============================================================================
// void prescription::display()
// {
//
// }
