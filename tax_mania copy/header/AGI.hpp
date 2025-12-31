#pragma once
#include "income.hpp"    
#include "adjustments.hpp" 

class AGI {
public:
    // calculate AGI
    static double calculate(const Income& income, const Adjustments& adjustments);
   
};