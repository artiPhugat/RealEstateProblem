#include"../include/properties_repo.h"

Properties *PropertiesRepo::get_by_id(string id){
    vector<Properties>::iterator it;
    for (it = propVec.begin(); it != propVec.end(); ++it)
    {
        if(id.compare(it->Id) == 0)
        {
            Properties *Prop = new Properties;
            Prop->Id = it->Id;
            Prop->Price = it->Price;
            Prop->Latitude = it->Latitude;
            Prop->Longitude = it->Longitude;
            Prop->num_of_bathrooms = it->num_of_bathrooms;
            Prop->num_of_bedrooms = it->num_of_bedrooms;
            Prop->Type = it->Type;
            Prop->Status = it->Status;
            return Prop;
        }
        //else
          //  return NULL;
    }
}


Properties* PropertiesRepo::add_dummy_property(string Id){
    cout<<"Dummy Property Added\n";
    Properties *Prop = new Properties;

    (Prop->Id).assign(Id);
    Prop->Latitude = 2.2;
    Prop->Longitude = 5.2;
    Prop->Price = 20000;
    Prop->num_of_bedrooms = 2;
    Prop->num_of_bathrooms = 2;
    Prop->Type = SALE;
    Prop->Status = AVAILABLE;

    propVec.insert(propVec.begin(), *Prop);
    return Prop;
}


Properties* PropertiesRepo::add_new(string id){
    Properties *Prop = get_property_attributes(id);
    propVec.insert(propVec.begin(), *Prop);
    return Prop;
}

vector<Properties> PropertiesRepo::find_all(){
    return propVec;
}

void PropertiesRepo::display_all(){
    vector<Properties>::iterator it;
    cout << "\n Display all Properties \n";
    for (it = propVec.begin(); it != propVec.end(); ++it)
    {
        cout << "ID:\t\t\t\t\t Price:\t\t Latitude:\t Longitude:\t";
        cout << "num_of_bedrooms:\t num_of_bathrooms:\t";
        cout << "Type:\t Status:\t\n";
        cout << it->Id <<"\t " << it->Price <<"\t\t ";
        cout << it->Latitude <<"\t\t "<< it->Longitude;
        cout << it->Price <<"\t" << it->num_of_bedrooms <<"\t\t\t  ";
        cout << it->num_of_bathrooms <<"\t\t\t " <<it->Type <<"\t ";
        cout << it->Status <<"\n";
    }
}
