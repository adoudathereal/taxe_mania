#include "../header/AGI.hpp"

// calculation of Adjusted Gross Income.
double AGI::calculate(const Income& income, const Adjustments& adjustments) {
    return income.getTotal() - adjustments.getTotal(); // AGI = Total Income - Adjustments
}