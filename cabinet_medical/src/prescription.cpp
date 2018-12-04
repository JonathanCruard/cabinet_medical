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
    cout << "Enter Prescriptor ID" << '\n';
    cin >> this->_prescriptor;
}

void prescription::set_date()
{
    cout << "Enter prescription date" << '\n';
    date _prescription_date;
}

void prescription::append_drug()
{
    cout << "add drug to prescription? Yes(Y)" << '\n';
    string add_drug;
    cin >> add_drug;
    while (add_drug=="Y")
    {
        drug_struct new_drug;
        _drugs.push_back(new_drug);
        cout << "add an other drug to prescription? Yes(Y)" << '\n';
        cin >> add_drug;
    }

}
//==============================================================================
// Displayer
//==============================================================================
void prescription::display()
{
    cout << "Prescriptor ID : " << _prescriptor << '\n';
    cout << "Date : ";
    _prescription_date.display();
    cout << "Drug list : " << '\n';
    for (auto t : _drugs) {
        t.display();
    }
}
