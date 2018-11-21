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

void prescription::append_drug()
{
    std::cout << "add drug to prescription? Yes(Y)" << '\n';
    string add_drug;
    std::cin >> add_drug;
    while (add_drug=="Y")
    {
        drug_struct new_drug_struct;
        _drugs.push_back(new_drug_struct);
        std::cout << "add an other drug to prescription? Yes(Y)" << '\n';
        std::cin >> add_drug;
    }

}
//==============================================================================
// Displayer
//==============================================================================
// void prescription::display()
// {
//
// }
