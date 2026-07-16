# pragma once
#include"Queue.h"
#include"Set.h"
#include"PageStorage.h"
#include <string>




class Frontier{

    struct URL{
        std::string link;
        int depth;
    };
    std::string getDate();
    Queue<URL>queue;
    PageStorage pages;

    
    public:
    void put(std::string& link,int depth,int max,int Id);
    size_t putSeed(std::string& link,std::string& html,int max,int depth=0);
    URL pop();
    bool empty();
    std::string getLink();
    int getDepth();
    size_t getSize();
    void backup();
    
    
};