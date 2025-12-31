#include "../header/adjustments.hpp"

// Sums all  variables.
double Adjustments::getTotal() const {
    return ira_contribution + student_loan_interest + educator_expenses +
           HSA_contribution + self_employment_tax + SEP + SIMPLE +
           qualified_retirement_plan;
}