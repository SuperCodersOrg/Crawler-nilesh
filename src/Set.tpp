#include "../include/Set.h"


// insert()
template<typename V>
void set<V>::insert(V val){
    map.insert(V,true);
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

