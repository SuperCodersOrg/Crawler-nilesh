# pragma once
#include"Queue.h"
#include"Set.h"
#include <string>

using namespace std;


class Frontier{

    struct URL{
        string link;
        int depth;
        string lastCrawl;
    };
    string getDate();
    Queue<URL>queue;
    
    public:
    void put(string& link,int depth);
    URL pop();
    bool empty();
    string getLink();
    int getDepth();
    size_t getSize();
    
    
};