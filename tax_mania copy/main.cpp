#include <iostream>
#include <string>


// Include headers from the 'header/' subdirectory
#include "header/taxpayer.hpp"
#include "header/income.hpp"
#include "header/adjustments.hpp"
#include "header/AGI.hpp"
#include "header/magi.hpp"
#include "header/standard_deduction.hpp"
#include "header/tax_constants_2024.hpp" 
#include "header/tax_bracket.hpp"        

// Function to get filing status from user
FilingStatus getFilingStatusFromUser() {
    int choice;
    std::cout << "\n--- Select Your Filing Status ---\n";
    std::cout << "1. Single\n";
    std::cout << "2. Married Filing Jointly\n";
    std::cout << "3. Head of Household\n";
    std::cout << "4. Married Filing Separately\n";
    std::cout << "5. Qualifying Widow(er)\n";
    std::cout << "Enter your choice (1-5): ";
    std::cin >> choice;
   
  switch(choice) {
        case 1: return FilingStatus::Single;
        case 2: return FilingStatus::MarriedFilingJointly;
        case 3: return FilingStatus::HeadOfHousehold;
        case 4: return FilingStatus::MarriedFilingSeparately;
        case 5: return FilingStatus::QualifyingWidower;
        default: 
            std::cout << "Invalid choice. Defaulting to Single.\n";
            return FilingStatus::Single;
}
}

// Function to get income information from user
Income getIncomeFromUser() {
    Income income;
    std::cout << "\n--- Enter Your Income Details ---\n";
    
    std::cout << "Wages, salaries, tips: $";
    std::cin >> income.wage;
    
    std::cout << "Taxable interest income: $";
    std::cin >> income.interest_income;
    
    std::cout << "Dividend income: $";
    std::cin >> income.dividend_income;
    
    std::cout << "Unemployment compensation: $";
    std::cin >> income.unemployment_compensation;
    
    std::cout << "Retirement distributions: $";
    std::cin >> income.retirement_distribution;
    
    std::cout << "Other taxable income: $";
    std::cin >> income.other_income;
    
    std::cout << "Business income (net profit/loss): $";
    std::cin >> income.business_income;
    
    return income;
}

// Function to get adjustments from user
Adjustments getAdjustmentsFromUser() {
    Adjustments adj;
    std::cout << "\n--- Enter Your Adjustments (Above-the-Line Deductions) ---\n";
    
    std::cout << "Traditional IRA contributions: $";
    std::cin >> adj.ira_contribution;
    
    std::cout << "Student loan interest paid: $";
    std::cin >> adj.student_loan_interest;
    
    std::cout << "Educator expenses: $";
    std::cin >> adj.educator_expenses;
    
    std::cout << "Health Savings Account (HSA) contributions: $";
    std::cin >> adj.HSA_contribution;
    
    std::cout << "Self-employment tax (½ of total): $";
    std::cin >> adj.self_employment_tax;
    
    std::cout << "SEP IRA contributions: $";
    std::cin >> adj.SEP;
    
    std::cout << "SIMPLE IRA contributions: $";
    std::cin >> adj.SIMPLE;
    
    std::cout << "Qualified retirement plan contributions: $";
    std::cin >> adj.qualified_retirement_plan;
    
    return adj;
}


//main program points


int main() {
    std::cout << "========================================\n";
    std::cout << "    2024 U.S. FEDERAL TAX CALCULATOR\n";
    std::cout << "========================================\n\n";
    

    // STEP 1: Get Personal Information

    std::cout << "PERSONAL INFORMATION SECTION\n";
    std::cout << "----------------------------\n";
    
    FilingStatus userStatus = getFilingStatusFromUser();
    
    bool isOver65;
    std::cout << "Are you 65 or older? (1 for Yes, 0 for No): ";
    std::cin >> isOver65;
    
    bool isBlind;
    std::cout << "Are you legally blind? (1 for Yes, 0 for No): ";
    std::cin >> isBlind;
    
    // Create the TaxPayer object
    TaxPayer user(userStatus, isOver65, isBlind);
    std::cout << "\n✓ Taxpayer profile created: " << user.getFilingStatusString();
    if (user.isOver65()) std::cout << " (65+ years)";
    if (user.isBlind()) std::cout << " (Blind)";
    std::cout << "\n";
    

    // STEP 2: Get Financial Information

    std::cout << "\nFINANCIAL INFORMATION SECTION\n";
    std::cout << "------------------------------\n";
    
    Income userIncome = getIncomeFromUser();
    std::cout << "✓ Total Income: $" << userIncome.getTotal() << "\n";
    
    Adjustments userAdjustments = getAdjustmentsFromUser();
    std::cout << "✓ Total Adjustments: $" << userAdjustments.getTotal() << "\n";
    

    // STEP 3: Perform Core Calculations

    std::cout << "\nCALCULATION RESULTS\n";
    std::cout << "--------------------\n";
    
    double agi = AGI::calculate(userIncome, userAdjustments);
    std::cout << "Adjusted Gross Income (AGI): $" << agi << "\n";
    
    // MAGI calculation updated with correct parameters
    double magi = MAGI::calculate(agi, userAdjustments);
    std::cout << "Modified AGI (MAGI): $" << magi << "\n";
    
    double standardDed = StandardDeduction::calculate(user);
    std::cout << "Standard Deduction: $" << standardDed << "\n";

    //   Calculate Taxable Income and Tax 
    double taxableIncome = agi - standardDed;
    if (taxableIncome < 0) taxableIncome = 0.0;
    std::cout << "Taxable Income: $" << taxableIncome << "\n";

    double incomeTax = TaxBracket::calculateTax(taxableIncome, userStatus);
    std::cout << "Federal Income Tax: $" << incomeTax << "\n";


    // STEP 4: Display Summary

  std::cout << "\n========================================\n";
    std::cout << "          2024 TAX CALCULATION SUMMARY\n"; 
    std::cout << "========================================\n";
    std::cout << "Filing Status: " << user.getFilingStatusString() << "\n";
    std::cout << "Total Income: $" << userIncome.getTotal() << "\n";
    std::cout << "Total Adjustments: $" << userAdjustments.getTotal() << "\n";
    std::cout << "Adjusted Gross Income (AGI): $" << agi << "\n";
    std::cout << "Modified AGI (MAGI): $" << magi << "\n";
    std::cout << "Standard Deduction: $" << standardDed << "\n";
    std::cout << "Taxable Income: $" << taxableIncome << "\n";
    std::cout << "Federal Income Tax: $" << incomeTax << "\n"; 
    std::cout << "========================================\n\n";
    

    // STEP 5: Future Features (Placeholders)

    std::cout << "FEATURES TO BE IMPLEMENTED:\n";
    std::cout << "----------------------------\n";
    std::cout << "1. Standard/Itemized Deduction Calculator\n";
    std::cout << "2. 2024 Senior Bonus Deduction Calculator\n";
    std::cout << "3. Tax Bracket Calculator\n";
    std::cout << "4. Tax Credit Calculator\n";
    std::cout << "5. Final Tax Liability/Refund Calculator\n\n";
    
    std::cout << "Thank you for using the 2024 Tax Calculator!\n";
    
    return 0;
}