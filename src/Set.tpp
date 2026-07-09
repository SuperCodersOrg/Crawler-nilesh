#include "../include/Set.h"


// insert()
template<typename V>
void set<V>::insert(V val){
    map.insert(val,true);
}

// exists()
template<typename V>
bool set<V>::exists(V val){
    return map.exists(val);
}

// remove()
template<typename V>
void set<V>::remove(V val){
    map.remove(val);
}

// size()
template<typename V>
size_t set<V>::size(){
    return map.size();
}


// getAll()
template<typename V>
DynamicArray<V> set<V>::getAll(){
    DynamicArray<V>get;
    get=map.getkeys();
    return get;
}

// clear()
template<typename V>
void set<V>::clear(){
    map.clear();
}