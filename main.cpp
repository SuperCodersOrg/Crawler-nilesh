#include<string>
#include "include/Set.h"
#include "include/STL/HashMap.h"

using namespace std;


int main() {
    set<string>s;
    HashMap<string,bool>map;
    map.insert("fsd",true);
    map.insert("fsd1",true);
    map.insert("fsd2",true);
    map.remove("fsd");
    cout<<map.size();
    DynamicArray<string>sst;
    sst=map.getkeys();

    
    
    
}