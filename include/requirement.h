#ifndef REQUIREMENT_H
#define REQUIREMENT_H
#include"header.h"

enum REQTYPE
{
    BUY=0,
    RENTER
};

enum REQSTATUS
{
    ACTIVE=0,
    STATE
};

class Requirements
{
    string Id;
    double Latitude;
    double Longitude;
    float minBudget;
    float maxBudget;
    int min_num_of_bedrooms;
    int max_num_of_bedrooms;
    int min_num_of_bathrooms;
    int max_num_of_bathrooms;
    REQTYPE Type;
    REQSTATUS Status;
    //List<Properties> ListofProperties;
};

#endif
