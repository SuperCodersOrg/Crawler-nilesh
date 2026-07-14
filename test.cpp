#include "include/Normalizer.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

    Normalizer n;
    DynamicArray<string>s;
    s=n.ignoreDomain.getAll();
    for(int i=0;i<s.size();i++){
        cout<<s[i]<<endl;
    }
}