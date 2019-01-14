#ifndef REQUIREMENT_REPO_H
#define REQUIREMENT_REPO_H
#include"requirement.h"

class RequirementsRepo : public BaseRepo<Requirements>{
    private:
        vector<Requirements> reqVec;

    public:
        Requirements *get_by_id(string id);
        Requirements *add_new(string id);
        Requirements *add_dummy_requirement(string id);
        vector<Requirements> find_all();
        void display_all();

        ~RequirementsRepo(){
            cout <<"RequirementsRepo Destructor\n";
        }
};


#endif

