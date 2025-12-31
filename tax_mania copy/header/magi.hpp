#pragma once
#include "adjustments.hpp"

class MAGI {
public:
    // calculate MAGI 
    static double calculate(double agiValue, const Adjustments& adjustments);
};