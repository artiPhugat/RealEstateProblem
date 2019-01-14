//#include"../include/properties.h"
#include"../include/properties_repo.h"
//#include"../include/requirement.h"
#include"../include/requirement_repo.h"

static double haversine(double lat1, double lon1, double lat2, double lon2);

bool validate_budget(double price, double minBudget, double maxBudget);

bool validate_bedrooms(int bedrooms, int minBedrooms, int maxBedrooms);

bool validate_bathrooms(int bathrooms, int minBathrooms, int maxBathrooms);

vector<Properties> get_matching_properties(Requirements *req);

float calculate_distance_score(double distance);

float calculate_budget_score(double Price, double minBudget, double maxBudget);

float calculate_bedroom_score(int num_of_bedrooms, int min_num_of_bedrooms, int max_num_of_bedrooms);

float calculate_bathroom_score(int num_of_bathrooms, int min_num_of_bathrooms, int max_num_of_bathrooms);

vector<Properties> get_valid_properties(Requirements *Req);


