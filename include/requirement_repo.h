#ifndef REQUIREMENT_REPO_H
#define REQUIREMENT_REPO_H
#include"../include/requirement.h"

class RequirementsRepo : public BaseRepo<Requirements>{
    private:
        vector<Requirements> reqVec;

    public:
        Requirements *get_by_id(string id);
        void add_new(string id);
        void find_all();

        ~RequirementsRepo(){
            cout <<"RequirementsRepo Destructor\n";
        }
};

#endif

