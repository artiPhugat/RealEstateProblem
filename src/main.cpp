#include"../include/header.h"
#include"../include/properties.h"
#include"../include/properties_repo.h"
#include"../include/requirement.h"
#include"../include/requirement_repo.h"

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
    //RequirementsRepo *R = new RequirementsRepo;
    do
    {
        cout<<"\nSelect the option \n";
        cout<<"1. Add New Dummy Property \n";
        cout<<"2. Add New Property\n";
        cout<<"3. Display all Properties\n";
        cout<<"4. New Search Request \n";
        cout<<"5. Display All Requirements\n";
        cout<<"Option Selected : ";
        cin>>option;
        switch(option)
        {
            case 1: P->add_dummy_property(get_new_id());
                    P->find_all();
                    break;

            case 2: P->add_new(get_new_id());
                    P->find_all();
                    break;

            case 3: P->find_all(); 
                    break;

            case 4: //R->add_new(get_new_id()); 
                    break;

            case 5: //R->find_all();
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
