#ifndef PROPERTIES_REPO_H
#define PROPERTIES_REPO_H
#include"../include/properties.h"

class PropertiesRepo : public BaseRepo<Properties> {
    private:
        vector<Properties> propVec;

    public:
        Properties *get_by_id(string id);
        Properties *add_new(string id);
        Properties *add_dummy_property(string id);
        vector<Properties> find_all();
        void display_all();

        ~PropertiesRepo(){
            cout <<"PropertiesRepo Destructor called\n";
        }
};

#endif
