#pragma once
#include "STL/HashMap.h"


template<typename V>
class Set{
    private:
    HashMap<V,bool>map;

    public:
    void insert(V val);
    bool exists(V val);
    void remove(V val);
    size_t size();
    DynamicArray<V> getAll();
    void clear();

};

#include "../src/Set.tpp"