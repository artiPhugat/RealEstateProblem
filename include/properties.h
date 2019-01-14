#ifndef PROPERTIES_H
#define PROPERTIES_H
#include"header.h"

enum PROPTYPE
{
    SALE=0,
    RENTAL,
};

enum PROPSTATUS
{
    AVAILABLE =0,
    SOLD,
};

class Properties
{
    public:
    string Id;
    double Latitude;
    double Longitude;
    float Price;
    int num_of_bedrooms;
    int num_of_bathrooms;
    PROPTYPE Type;
    PROPSTATUS Status;
};

// Function declaration
Properties *get_property_attributes(string id);
void display_property(Properties *P);

#endif
