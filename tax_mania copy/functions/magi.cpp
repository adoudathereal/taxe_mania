#include "../header/magi.hpp"



double MAGI::calculate(double agiValue, const Adjustments& adj) {
    double magi = agiValue; 

    
    magi += adj.student_loan_interest;

    return magi;
}