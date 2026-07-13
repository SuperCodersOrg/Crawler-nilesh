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
    set<string>visited;
    
    
    public:
    bool exists(string link);
    void put(string& link,int depth);
    URL pop();
    bool empty();
    string getLink();
    int getDepth();
    
    
};