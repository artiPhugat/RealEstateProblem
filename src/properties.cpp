#include"../include/properties.h"

/*
 * For simplicity getting properties attributes from console
 */
Properties *get_property_attributes(string id)
{
    cout<<"Enter New Property Attributes\n";
    double Latitude;
    double Longitude;
    float Price;
    int num_of_bedrooms;
    int num_of_bathrooms;
    PROPTYPE Type;
    PROPSTATUS Status;

    cout<<"\nEnter Latitude :";
    cin>>Latitude;
    cout<<"\nEnter Longitude :";
    cin>>Longitude;

    cout<<"\nEnter Price :";
    cin>>Price;
    cout<<"\nEnter num_of_bedrooms:";
    cin>>num_of_bedrooms;
    cout<<"\nEnter num_of_bathrooms:";
    cin>>num_of_bathrooms;

    Type = SALE;
    Status = AVAILABLE;
        
    Properties *Prop = new Properties;
    Prop->Id = id;
    Prop->Latitude = Latitude;
    Prop->Longitude = Longitude;
    Prop->Price = Price;
    Prop->num_of_bedrooms = num_of_bedrooms;
    Prop->num_of_bathrooms = num_of_bathrooms;
    Prop->Type = Type;
    Prop->Status = Status;
    return Prop;
}


/*
 * These attributes can be stored in MongoDB
 */
void display_property(Properties *it)
{
    //cout<<"\nDisplay Property with ID :" << it->Id <<"\n";

    cout << "\nID:\t\t\t\t Price:\t\t Latitude:\t Longitude:\t";
    cout << "num_of_bedrooms:\t num_of_bathrooms:\t";
    cout << "Type:\t Status:\t\n";
    cout << it->Id <<"\t " << it->Price <<"\t\t ";
    cout << it->Latitude <<"\t\t "<< it->Longitude;
    cout << it->Price <<"\t" << it->num_of_bedrooms <<"\t\t\t  ";
    cout << it->num_of_bathrooms <<"\t\t\t " <<it->Type <<"\t ";
    cout << it->Status <<"\n";
}
