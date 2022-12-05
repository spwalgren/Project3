#include "Job.h"

// constructor
Job::Job(std::string NAICS_TITLE_, std::string OCC_TITLE_, int A_PCT10_, int A_PCT25_, int A_MEDIAN_, int A_PCT75_, int A_PCT90_) {
    this->NAICS_TITLE = NAICS_TITLE_;
    this->OCC_TITLE = OCC_TITLE_;
    this->A_PCT10 = A_PCT10_;
    this->A_PCT25 = A_PCT25_;
    this->A_MEDIAN = A_MEDIAN_;
    this->A_PCT75 = A_PCT75_;
    this->A_PCT90 = A_PCT90_;
}

// get functions, to get the data
std::string Job::Get_NAICS_TITLE() {

    return NAICS_TITLE;
}

std::string Job::Get_OCC_TITLE() {

    return OCC_TITLE;
}

int Job::Get_A_PCT10() {

    return A_PCT10;
}

int Job::Get_A_PCT25() {

    return A_PCT25;
}

int Job::Get_A_MEDIAN() {

    return A_MEDIAN;
}

int Job::Get_A_PCT75() {

    return A_PCT75;
}

int Job::Get_A_PCT90() {

    return A_PCT90;
}