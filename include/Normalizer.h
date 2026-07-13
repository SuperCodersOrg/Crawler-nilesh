#pragma once
#include <string>
#include"STL/DynamicArray.h"
#include"Frontier.h"
using namespace std;


class Normalizer{
    private:
    void To_lower(string& link);
    void removeFragment(string& link);
    void normalizePath(string &source);
    void relativeURL(string &source);
    set<string>ignoreDomain;
    set<string>ignoreExtension;
    Frontier frontier;

    
    
    public:
    bool isrelative(string &source);
    string seedLink;
    Normalizer();
    string normalize(string & link);
    DynamicArray<string> normalize(DynamicArray<string> & link);

};