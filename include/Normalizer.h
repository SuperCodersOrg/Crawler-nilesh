#pragma once
#include <string>
#include"STL/DynamicArray.h"
#include"Frontier.h"
using namespace std;


class Normalizer{
    private:
    const string DOMAIN_FILE = "../src/ignore/domain.txt";
    const string EXTENSION_FILE = "../src/ignore/extension.txt";
    string read(string page);
    void To_lower(string& link);
    void removeFragment(string& link);
    void normalizePath(string &source);
    void relativeURL(string &source);
    Frontier frontier;
    
    
    
    public:
    set<string>ignoreExtension;
    set<string>ignoreDomain;
    bool isrelative(string &source);
    string seedLink;
    Normalizer();
    void normalize(string & link);
    DynamicArray<string> normalize(DynamicArray<string> & link);

};