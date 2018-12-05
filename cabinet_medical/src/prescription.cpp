#include "prescription.hpp"

//==============================================================================
// Constructors
//==============================================================================
prescription::prescription() : _prescription_date()
{
    set_prescriptor();
    append_drug();
}

prescription::prescription(int prescriptor, date prescription_date, list<drug_struct> drugs) : _prescription_date(prescription_date)
{
    set_prescriptor(prescriptor);
    this->_drugs = drugs;
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
    date dat_to_set;
    this->_prescription_date = dat_to_set;
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

void prescription::set_prescriptor(int prescriptor)
{
    this->_prescriptor = prescriptor;
}

//==============================================================================
// Getters
//==============================================================================
int prescription::get_prescriptor()
{
    return _prescriptor;
}

date prescription::get_date()
{
    return _prescription_date;
}

list<drug_struct> prescription::get_drugs()
{
    return _drugs;
}

//==============================================================================
// Displayer
//==============================================================================
void prescription::display()
{
    cout << "Prescriptor ID     : " << _prescriptor << '\n';
    _prescription_date.display();
    cout << "Drug list          : " << '\n';
    for (auto t : _drugs)
    {
        t.display();
    }
}
