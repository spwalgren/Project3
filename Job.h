#pragma once
#include <iostream>

class Job
{
private:

    // these are the data types, they have the same name as the columns and store their corresponding values in each specific row of the excel file
    std::string NAICS_TITLE;

    std::string OCC_TITLE;

    int A_PCT10;

    int A_PCT25;

    int A_MEDIAN;

    int A_PCT75;

    int A_PCT90;


public:

    // constructor
    Job(std::string NAICS_TITLE_, std::string OCC_TITLE_, int A_PCT10_, int A_PCT25_, int A_MEDIAN_, int A_PCT75_, int A_PCT90_);

    // these are the get functions, use them to retrieve the data
    std::string Get_NAICS_TITLE();

    std::string Get_OCC_TITLE();

    int Get_A_PCT10();

    int Get_A_PCT25();

    int Get_A_MEDIAN();

    int Get_A_PCT75();

    int Get_A_PCT90();
};
