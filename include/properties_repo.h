#ifndef PROPERTIES_REPO_H
#define PROPERTIES_REPO_H
#include"../include/properties.h"

class PropertiesRepo : public BaseRepo<Properties> {
    private:
        vector<Properties> propVec;

    public:
        Properties *get_by_id(string id);
        void add_new(string id);
        void add_dummy_property(string id);
        void find_all();

        ~PropertiesRepo(){
            cout <<"PropertiesRepo Destructor called\n";
        }
};

#endif
