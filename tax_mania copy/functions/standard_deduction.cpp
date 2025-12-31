#include "../header/standard_deduction.hpp"

double StandardDeduction::calculate(const TaxPayer& taxpayer) {
    FilingStatus status = taxpayer.getFilingStatus();
    double deduction = 0.0;

    //  Base  Standard Deduction
    if (status == FilingStatus::Single) {
        deduction = Tax2024::STANDARD_DEDUCTION_SINGLE;
    } else if (status == FilingStatus::MarriedFilingJointly) {
        deduction = Tax2024::STANDARD_DEDUCTION_JOINT;
    } else if (status == FilingStatus::HeadOfHousehold) {
        deduction = Tax2024::STANDARD_DEDUCTION_HOH;
    } else if (status == FilingStatus::MarriedFilingSeparately) {
       
        deduction = Tax2024::STANDARD_DEDUCTION_SINGLE;
    } else if (status == FilingStatus::QualifyingWidower) {
        
        deduction = Tax2024::STANDARD_DEDUCTION_JOINT;
    }

    // Additional Deduction for Age 65+
    if (taxpayer.isOver65()) {
        if (status == FilingStatus::Single || status == FilingStatus::HeadOfHousehold) {
            deduction += Tax2024::AGE_BLIND_BONUS_SINGLE;
        } else if (status == FilingStatus::MarriedFilingJointly || 
                   status == FilingStatus::QualifyingWidower) {
           
            deduction += Tax2024::AGE_BLIND_BONUS_MARRIED;
           
        } else if (status == FilingStatus::MarriedFilingSeparately) {
            deduction += Tax2024::AGE_BLIND_BONUS_SINGLE; 
        }
    }

    //   Additional Deduction for Blindness 
    if (taxpayer.isBlind()) {
        if (status == FilingStatus::Single || status == FilingStatus::HeadOfHousehold) {
            deduction += Tax2024::AGE_BLIND_BONUS_SINGLE;
        } else if (status == FilingStatus::MarriedFilingJointly || 
                   status == FilingStatus::QualifyingWidower) {
            deduction += Tax2024::AGE_BLIND_BONUS_MARRIED;
        } else if (status == FilingStatus::MarriedFilingSeparately) {
            deduction += Tax2024::AGE_BLIND_BONUS_SINGLE;
        }
    }

    return deduction;
}