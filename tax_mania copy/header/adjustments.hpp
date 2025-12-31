#pragma once

class Adjustments {
public:
     
     double ira_contribution = 0.0;
     double student_loan_interest = 0.0;
     double educator_expenses = 0.0;
     double HSA_contribution = 0.0;
     double self_employment_tax = 0.0;
     double SEP = 0.0;
     double SIMPLE = 0.0;
     double qualified_retirement_plan = 0.0;

     double getTotal() const;
};