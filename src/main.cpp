#include"../include/header.h"
#include"../include/properties.h"
#include"../include/properties_repo.h"
#include"../include/requirement.h"
#include"../include/requirement_repo.h"
#include"../include/helper.h"

string get_new_id()
{
    uuid_t uuid;
    char uuid_str[37];
    uuid_generate(uuid);
    uuid_unparse_lower(uuid, uuid_str);
    string str = uuid_str;
    return str;
}

int main()
{
    char c ;
    int option;

    PropertiesRepo *P = new PropertiesRepo;
    RequirementsRepo *R = new RequirementsRepo;

    P->add_dummy_property(get_new_id());
    P->add_dummy_property(get_new_id());
    P->add_dummy_property(get_new_id());

    P->display_all();

    Requirements *req = R->add_dummy_requirement(get_new_id());
    R->display_all();
    vector<Properties> Prop1 = get_valid_properties(req);
    cout<< "Size : "<<Prop1.size()<<"\n";
    display_properties_list(Prop1);
    req->matchProperties = Prop1;
    /*
       Properties *Prop = P->add_dummy_property(get_new_id());
       cout<<"\n\n\ ID : " <<Prop->Id;
       P->display_all();
       Properties *newP = P->get_by_id(Prop->Id);
       display_property(newP);
       */

    do
    {
        cout<<"\nSelect the option \n";
        cout<<"1. Add New Dummy Property \n";
        cout<<"2. Add New Property\n";
        cout<<"3. Display all Properties\n";
        cout<<"4. New Search Request \n";
        cout<<"5. Display All Requirements\n";
        cout<<"6. Add Dummy Requirement\n";
        cout<<"7. Calculate Score with Requirement\n";
        cout<<"Option Selected : ";
        cin>>option;
        switch(option)
        {
            case 1: P->add_dummy_property(get_new_id());
                    P->display_all();
                    break;

            case 2: P->add_new(get_new_id());
                    P->display_all();
                    break;

            case 3: P->display_all();
                    break;

            case 4: R->add_new(get_new_id());
                    R->display_all();
                    break;

            case 5: R->find_all();
                    break;

            case 6: R->add_dummy_requirement(get_new_id());
                    R->display_all();
                    break;

            case 7: {
                        Requirements *req = R->add_dummy_requirement(get_new_id());
                        R->display_all();
                        vector<Properties> Prop1 = get_valid_properties(req);
                        cout<< "Size : "<<Prop1.size()<<"\n";
                        display_properties_list(Prop1);
                        req->matchProperties = Prop1;
                    }
                    break;

            default : cout<<"Please select above option\n"; break;
        }
        cout<<"\n\nDo you want to continue\n";
        cout <<"Press y to continue and any other key to exit : ";
        cin >>c;

    }while(c == 'y' || c == 'Y');
    cout<<"\n";
    return 0;
}
