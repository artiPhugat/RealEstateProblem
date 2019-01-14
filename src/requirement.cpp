#include"../include/requirement.h"

/*
 * For simplicity getting properties attributes from console
 */
Requirements *get_attributes(string id)
{
    Requirements *Req = new Requirements;
    cout<<"Enter New Requirement Attributes\n";
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

    cout<<"\nEnter Requirement Latitude :";
    cin>>Latitude;
    cout<<"\nEnter Requirement Longitude :";
    cin>>Longitude;

    cout<<"\nEnter Min and Max Budget :";
    cin>>minBudget>>maxBudget;
    cout<<"\nEnter min and max num_of_bedrooms:";
    cin>>min_num_of_bedrooms>>max_num_of_bedrooms;
    cout<<"\nEnter min and max num_of_bathrooms:";
    cin>>min_num_of_bathrooms>>max_num_of_bathrooms;

    Type = BUY;
    Status = ACTIVE;

    Req->Id = id;
    Req->Latitude = Latitude;
    Req->Longitude = Longitude;
    Req->minBudget = minBudget;
    Req->maxBudget = maxBudget;
    Req->min_num_of_bedrooms = min_num_of_bedrooms;
    Req->max_num_of_bedrooms = max_num_of_bedrooms;
    Req->min_num_of_bathrooms = min_num_of_bathrooms;
    Req->max_num_of_bathrooms = max_num_of_bathrooms;
    Req->Type = Type;
    Req->Status = Status;

    return Req;
}

void display_requirement(Requirements *it)
{
    cout << "ID:\t\t\t\t\t ";
    cout << "Min Budget:\t Max Budget:\t";
    cout << "Latitude:\t Longitude:\t\n";
    cout << it->Id <<"\t ";
    cout << it->minBudget <<"\t\t  " << it->maxBudget <<"\t\t";
    cout << it->Latitude <<"\t\t "<< it->Longitude;
    cout << "\n\nmin_num_of_bedrooms:  max_num_of_bedrooms: ";
    cout << "min_num_of_bathrooms:  max_num_of_bathrooms:\t";
    cout << "Type:\t Status:\t\n";
    cout << it->min_num_of_bedrooms <<"\t\t\t " << it->max_num_of_bedrooms<<"\t\t\t";
    cout << it->min_num_of_bathrooms <<"\t\t\t " << it->max_num_of_bathrooms<<"\t\t ";
    cout << it->Type <<"\t  ";
    cout << it->Status <<"\n";

}
