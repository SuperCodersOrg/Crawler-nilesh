#include "../include/Set.h"


// insert()
template<typename V>
void Set<V>::insert(V val){
    map.insert(val,true);
}

// exists()
template<typename V>
bool Set<V>::exists(V val){
    return map.exists(val);
}

// remove()
template<typename V>
void Set<V>::remove(V val){
    map.remove(val);
}

// size()
template<typename V>
size_t Set<V>::size(){
    return map.size();
}


// getAll()
template<typename V>
DynamicArray<V> Set<V>::getAll(){
    DynamicArray<V>get;
    get=map.getkeys();
    return get;
}

// clear()
template<typename V>
void Set<V>::clear(){
    map.clear();
}