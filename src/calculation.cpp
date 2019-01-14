#include"../include/helper.h"
/*
 *
 * NOTE : For simplicity functions are created and result is stored in vector
 * Actual data will be saved in elastic search for faster query
 *
 *
 */
static double haversine(double lat1, double lon1, double lat2, double lon2)
{
    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    // convert to radians
    lat1 = (lat1) * M_PI / 180.0;
    lat2 = (lat2) * M_PI / 180.0;

    // apply formulae
    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double rad = 6371;
    double c = 2 * asin(sqrt(a));
    return rad * c;
}

bool validate_budget(double price, double minBudget, double maxBudget)
{
    if(minBudget == 0){
        if(0.75 * price <= maxBudget <= 1.25 * price)
            return true;
        else
            return false;
    }
    else if(maxBudget == 0){
        if(0.75 * price <= minBudget <= 1.25 * price)
            return true;
        else
            return false;
    }
    else if(minBudget <= price <= maxBudget)
        return true;
    else
        return false;
}

bool validate_bedrooms(int bedrooms, int minBedrooms, int maxBedrooms)
{
    if(minBedrooms == 0){
        if( abs(maxBedrooms-2) <= bedrooms <= maxBedrooms+2)
            return true;
        else
            return false;
    }
    else if(maxBedrooms == 0){
        if( abs(minBedrooms-2) <= bedrooms <= minBedrooms+2)
            return true;
        else
            return false;
    }
    else if(minBedrooms <= bedrooms <= maxBedrooms)
        return true;
    else
        return false;
}

bool validate_bathrooms(int bathrooms, int minBathrooms, int maxBathrooms)
{
    if(minBathrooms == 0){
        if( abs(maxBathrooms-2) <= bathrooms <= maxBathrooms+2)
            return true;
        else
            return false;
    }
    else if(maxBathrooms == 0){
        if( abs(minBathrooms-2) <= bathrooms <= minBathrooms+2)
            return true;
        else
            return false;
    }
    else if(minBathrooms <= bathrooms <= maxBathrooms)
        return true;
    else
        return false;
}


//NOTE : For simplicity done this way, actually geo distance elastic API will be used
//Properties will be saved in elastic and this will be for similar for all cased
//Call geo distance elastic API with distance 10 miles
vector<Properties> get_matching_properties(Requirements *req){
    PropertiesRepo *P = new PropertiesRepo;
    vector<Properties> allProp = P->find_all();
    vector<Properties> validProp;
    vector<Properties>::iterator it;
    for (it = allProp.begin(); it != allProp.end(); ++it)
    {
        double distance = haversine(it->Latitude, it->Latitude, req->Latitude, req->Latitude);
        cout<<"\nDistance : "<<distance <<"\n";
        if(0.0 <= distance <= 10.0)
        {
            cout<<"valid";
            if((validate_budget(it->Price, req->minBudget, req->maxBudget)) == true)
            {
                if((validate_bedrooms(it->num_of_bedrooms, req->min_num_of_bedrooms, req->max_num_of_bedrooms)) == true)
                {
                    if((validate_bathrooms(it->num_of_bathrooms, req->min_num_of_bathrooms, req->max_num_of_bathrooms)) == true)
                    {
                        validProp.insert(validProp.begin(), *it);
                        return validProp;
                    }

                }
            }
        }
    }
    return validProp;
}

float calculate_distance_score(double distance){
    if(0.0 <= distance <= 2.0)
        return 0.3;
    else
        return 0.3*((10-distance)/8);
}

float calculate_budget_score(double Price, double minBudget, double maxBudget){
    if(minBudget <= Price <= maxBudget)
        return 0.3;
    else if(minBudget == 0){
        if(0.90 * Price <= maxBudget <= 1.10 * Price)
            return 0.3;
        else
            return 0.3*((25-maxBudget)/15);
    }
    else if(maxBudget == 0){
        if(0.90 * Price <= minBudget <= 1.10 * Price)
            return 0.3;
        else
            return 0.3*((25-minBudget)/15);
    }
    else
        return 0;
}

float calculate_bedroom_score(int num_of_bedrooms, int min_num_of_bedrooms, int max_num_of_bedrooms){
    if(min_num_of_bedrooms <= num_of_bedrooms <= max_num_of_bedrooms)
        return 0.2;
    else if(min_num_of_bedrooms == 0)
        return 0.2*((4 - max_num_of_bedrooms)/2);
    else if(max_num_of_bedrooms == 0)
        return 0.2*((4 - min_num_of_bedrooms)/2);
    else
        return 0;
}

float calculate_bathroom_score(int num_of_bathrooms, int min_num_of_bathrooms, int max_num_of_bathrooms){
    if(min_num_of_bathrooms <= num_of_bathrooms <= max_num_of_bathrooms)
        return 0.2;
    else if(min_num_of_bathrooms == 0)
        return 0.2*((4 - max_num_of_bathrooms)/2);
    else if(max_num_of_bathrooms == 0)
        return 0.2*((4 - min_num_of_bathrooms)/2);
    else
        return 0;
}


vector<Properties> get_valid_properties(Requirements *req)
{
    vector<Properties> allProp = get_matching_properties(req);
    vector<Properties> Prop;
    vector<Properties>::iterator it;
    float distanceScore, budgetScore, bedroomScore, bathroomScore, totalScore;
    for (it = allProp.begin(); it != allProp.end(); ++it)
    {
        double distance = haversine(it->Latitude, it->Longitude, req->Latitude, req->Longitude);
        distanceScore = calculate_distance_score(distance);
        cout <<"\nDistance Score : "<<distanceScore<<"\n";

        budgetScore = calculate_budget_score(it->Price, req->minBudget, req->maxBudget);
        cout <<"\nBudget Score : "<<budgetScore<<"\n";

        bedroomScore = calculate_bedroom_score(it->num_of_bedrooms, req->min_num_of_bedrooms, req->max_num_of_bedrooms);
        cout <<"\n bedroomScore : "<<bedroomScore <<"\n";

        bathroomScore = calculate_bathroom_score(it->num_of_bathrooms, req->min_num_of_bathrooms, req->max_num_of_bathrooms);
        cout <<"\n bathroomScore : "<<bathroomScore <<"\n";

        totalScore = (distanceScore + budgetScore + bedroomScore + bathroomScore);
        cout<<"\n Total Score : "<<totalScore<<"\n";

        if(totalScore >= 0.4)
        {
            Prop.insert(Prop.begin(), *it);
            return Prop;
        }
    }
    return Prop;
}

