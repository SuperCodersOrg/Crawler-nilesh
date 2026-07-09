#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include "include/STL/HashMap.h"

using namespace std;


int main() {
    HashMap<string,int>map;
    map.insert("hi",1);
    map.insert("hi2",2);
    map.insert("h3i",3);
    map.insert("hi4",4);
    map.insert("hi4",5);
    map.insert("hi5",6);
    map.insert("hi6",7);
    map.insert("hi7",8);
    map.insert("hi8",18);

    DynamicArray<string>s;
    s=map.getkeys();

    for(int i=0;i<s.size();i++){
        cout<<s[i]<<endl;
    }
    

    
    
}