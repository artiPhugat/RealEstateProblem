#include"../include/requirement_repo.h"

Requirements *RequirementsRepo::get_by_id(string id){
    vector<Requirements>::iterator it;
    for (it = reqVec.begin(); it != reqVec.end(); ++it)
    {
        if(id.compare(it->Id) == 0)
        {
            Requirements *Req = new Requirements;
            Req->Id = it->Id;
            Req->minBudget = it->minBudget;
            Req->maxBudget = it->maxBudget;
            Req->Latitude = it->Latitude;
            Req->Longitude = it->Longitude;
            Req->min_num_of_bathrooms = it->min_num_of_bathrooms;
            Req->max_num_of_bathrooms = it->max_num_of_bathrooms;
            Req->min_num_of_bedrooms = it->min_num_of_bedrooms;
            Req->max_num_of_bedrooms = it->max_num_of_bedrooms;
            Req->Type = it->Type;
            Req->Status = it->Status;
            return Req;
        }
        //else
        //  return NULL;
    }
}

Requirements *RequirementsRepo::add_new(string id){
    Requirements *Req = get_attributes(id);
    reqVec.insert(reqVec.begin(), *Req);
    return Req;
}

Requirements *RequirementsRepo::add_dummy_requirement(string Id){
    cout<<"Dummy Requirement Added\n";
    Requirements *Req = new Requirements;

    (Req->Id).assign(Id);
    Req->Latitude = 2.2;
    Req->Longitude = 5.2;
    Req->minBudget = 10000;
    Req->maxBudget = 20000;
    Req->min_num_of_bedrooms = 1;
    Req->max_num_of_bedrooms = 2;
    Req->min_num_of_bathrooms = 2;
    Req->max_num_of_bathrooms = 1;
    Req->Type = BUY;
    Req->Status = ACTIVE;

    reqVec.insert(reqVec.begin(), *Req);
    return Req;
}


vector<Requirements> RequirementsRepo::find_all(){
    return reqVec;
}

void RequirementsRepo::display_all(){
    vector<Requirements>::iterator it;
    cout << "\n Display all Requirements \n";
    for (it = reqVec.begin(); it != reqVec.end(); ++it)
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
}

