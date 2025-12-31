#include "../header/tax_bracket.hpp"
#include "../header/tax_constants_2024.hpp"
#include <vector>

double TaxBracket::calculateTax(double taxableIncome, FilingStatus status) {
    const std::vector<double>* brackets = nullptr;
    const std::vector<double>* rates = nullptr;

    // Selection of choices
    switch (status) {
        case FilingStatus::Single:
            brackets = &Tax2024::SINGLE_BRACKETS;
            rates = &Tax2024::SINGLE_RATES;
            break;
        case FilingStatus::MarriedFilingJointly:
            brackets = &Tax2024::JOINT_BRACKETS;
            rates = &Tax2024::JOINT_RATES;
            break;
        case FilingStatus::HeadOfHousehold:
            brackets = &Tax2024::HOH_BRACKETS;
            rates = &Tax2024::HOH_RATES;
            break;
        case FilingStatus::MarriedFilingSeparately:
            brackets = &Tax2024::MFS_BRACKETS;
            rates = &Tax2024::MFS_RATES;
            break;
        case FilingStatus::QualifyingWidower:
     
            brackets = &Tax2024::JOINT_BRACKETS;
            rates = &Tax2024::JOINT_RATES;
            break;
        default:
            // Default 
            brackets = &Tax2024::SINGLE_BRACKETS;
            rates = &Tax2024::SINGLE_RATES;
    }


    double tax = 0.0;
    size_t numBrackets = brackets->size();

    for (size_t i = 1; i < numBrackets; ++i) {
        double bracketWidth = (*brackets)[i] - (*brackets)[i-1];
        if (taxableIncome > (*brackets)[i]) {
            tax += bracketWidth * (*rates)[i-1];
        } else {
            double incomeInThisBracket = taxableIncome - (*brackets)[i-1];
            tax += incomeInThisBracket * (*rates)[i-1];
            break;
        }
    }

    if (taxableIncome > (*brackets)[numBrackets-1]) {
        tax += (taxableIncome - (*brackets)[numBrackets-1]) * (*rates)[numBrackets-1];
    }

    return tax;
}