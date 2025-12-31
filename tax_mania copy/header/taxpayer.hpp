#include <iostream>
#include <string>
#pragma once



enum class FilingStatus {
    Single,
    MarriedFilingJointly,
    HeadOfHousehold,
    MarriedFilingSeparately,
    QualifyingWidower
};

inline std::string filingStatusToString(FilingStatus status) {
    switch (status) {
        case FilingStatus::Single:                 return "Single";
        case FilingStatus::MarriedFilingJointly:   return "Married Filing Jointly";
        case FilingStatus::HeadOfHousehold:        return "Head of Household";
        case FilingStatus::MarriedFilingSeparately:return "Married Filing Separately";
        case FilingStatus::QualifyingWidower:      return "Qualifying Widow(er)";
        default:                                   return "Unknown Status"; 
    }
}


class TaxPayer {
public:
    
    // CONSTRUCTOR
    // Parameters:
    //   status  : The filing status (from the FilingStatus enum).
    //   over65  : true if the taxpayer is age 65 or older by the end of 2025.
    //   blind   : true if the taxpayer is legally blind.
 
    TaxPayer(FilingStatus status, bool over65 = false, bool blind = false)
        : filing_status_(status), is_over_65_(over65), is_blind_(blind) {}



  
    FilingStatus getFilingStatus()  const { return filing_status_; }
    bool         isOver65()         const { return is_over_65_; }
    bool         isBlind()          const { return is_blind_; }


    std::string  getFilingStatusString() const { return filingStatusToString(filing_status_); }

private:
    
    // PRIVATE DATA MEMBERS

    FilingStatus filing_status_; // The core status, stored as a safe enum.
    bool         is_over_65_;    // Qualification for age-based deductions.
    bool         is_blind_;      // Qualification for blindness-based deductions.
};