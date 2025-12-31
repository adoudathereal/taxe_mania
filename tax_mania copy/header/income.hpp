#pragma once
#include <string>

class Income {
public:
     // Data members
     double wage= 0.0;
     double interest_income= 0.0;
     double dividend_income= 0.0;
     double unemployment_compensation= 0.0;
     double retirement_distribution= 0.0;
     double other_income= 0.0;
     double business_income= 0.0;

     double getTotal() const;
};
