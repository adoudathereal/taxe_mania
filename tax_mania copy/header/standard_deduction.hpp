// header/standard_deduction.hpp
#pragma once
#include "taxpayer.hpp"
#include "tax_constants_2024.hpp"

class StandardDeduction {
public:
    // Calculate standard deduction
    static double calculate(const TaxPayer& taxpayer);
};