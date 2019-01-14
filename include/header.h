#ifndef HEADER_H
#define HEADER_H

#include<iostream>
#include<vector>
#include <iterator>
#include <algorithm>
#include<list>
#include<string>
#include <uuid/uuid.h>

using namespace std;

template <typename T>

class BaseRepo{
    public:
    virtual T* get_by_id(string id) = 0;
    virtual void add_new(string id) = 0;
    virtual void find_all() = 0;
    virtual ~BaseRepo(){
        cout<<"BaseRepo Destructor called\n";
    };
};

#endif
