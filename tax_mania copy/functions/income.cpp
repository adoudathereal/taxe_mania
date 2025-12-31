#include "../header/income.hpp"

//  sums  variables.
double Income::getTotal() const {
    return wage + interest_income + dividend_income +
           unemployment_compensation + retirement_distribution +
           other_income + business_income;
}