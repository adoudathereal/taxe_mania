#pragma once
#include <vector>

namespace Tax2024 {
    // ========== STANDARD DEDUCTION  ==========
    const double STANDARD_DEDUCTION_SINGLE = 14600.0;
    const double STANDARD_DEDUCTION_JOINT  = 29200.0;
    const double STANDARD_DEDUCTION_HOH    = 21900.0;

    // Additional standard deduction for Age 65+ or Blind 
    const double AGE_BLIND_BONUS_SINGLE = 1950.0;   // Per condition (age OR blind)
    const double AGE_BLIND_BONUS_MARRIED = 1550.0; // Per spouse, per condition

    // ========== TAX BRACKETS & RATES  ==========

    // Single
    const std::vector<double> SINGLE_BRACKETS = {0.0, 11600.0, 47150.0, 100525.0, 191950.0, 243725.0, 609350.0};
    const std::vector<double> SINGLE_RATES    = {0.10, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37};

    // Married Filing Jointly
    const std::vector<double> JOINT_BRACKETS = {0.0, 23200.0, 94300.0, 201050.0, 383900.0, 487450.0, 731200.0};
    const std::vector<double> JOINT_RATES    = {0.10, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37};

    // Head of Household
    const std::vector<double> HOH_BRACKETS = {0.0, 16550.0, 63100.0, 100500.0, 191950.0, 243700.0, 609350.0};
    const std::vector<double> HOH_RATES    = {0.10, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37};

    // Married Filing Separately
    const std::vector<double> MFS_BRACKETS = {0.0, 11600.0, 47150.0, 100525.0, 191950.0, 243725.0, 365600.0};
    const std::vector<double> MFS_RATES    = {0.10, 0.12, 0.22, 0.24, 0.32, 0.35, 0.37};

    // ========== CONTRIBUTION LIMITS  ==========
    const double IRA_CONTRIBUTION_LIMIT = 7000.0;
    const double IRA_CATCH_UP_50_PLUS   = 8000.0; // For age 50+
}