#ifndef REQUIREMENT_H
#define REQUIREMENT_H
#include"../include/header.h"
#include"../include/properties.h"

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
    public:
    string Id;
    double Latitude;
    double Longitude;
    double minBudget;
    double maxBudget;
    int min_num_of_bedrooms;
    int max_num_of_bedrooms;
    int min_num_of_bathrooms;
    int max_num_of_bathrooms;
    REQTYPE Type;
    REQSTATUS Status;
    vector<Properties> matchProperties;
    //List<Properties> ListofProperties;
};

Requirements *get_attributes(string id);

void display_requirement(Requirements *it);
#endif
