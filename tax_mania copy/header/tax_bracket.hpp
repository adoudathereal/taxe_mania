#pragma once
#include "taxpayer.hpp"

class TaxBracket {
public:
    // Calculates income tax based on taxable income and filing status
    static double calculateTax(double taxableIncome, FilingStatus status);
};