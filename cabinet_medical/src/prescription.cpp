#include "prescription.hpp"

//==============================================================================
// Constructors
//==============================================================================
prescription::prescription()
{
    set_prescriptor();
    set_date();
    append_drug();
}

//==============================================================================
// Setters
//==============================================================================
void prescription::set_prescriptor()
{
    std::cin >> _prescriptor;
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
        drug_struct new_drug;
        _drugs.push_back(new_drug);
        std::cout << "add an other drug to prescription? Yes(Y)" << '\n';
        std::cin >> add_drug;
    }

}
//==============================================================================
// Displayer
//==============================================================================
void prescription::display()
{
    std::cout << "Prescriptor ID : " << _prescriptor << '\n';
    std::cout << "Date : ";
    _prescription_date.display();
    std::cout << "Drug list : " << '\n';
    for (auto t : _drugs) {
        t.display();
    }
}
