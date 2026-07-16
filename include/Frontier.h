# pragma once
#include"Queue.h"
#include"Set.h"
#include"Database.h"
#include <string>




class Frontier{

    struct URL{
        std::string link;
        int depth;
    };
    std::string getDate();
    Queue<URL>queue;
    Database database;

    
    public:
    void put(std::string& link,int depth);
    void putSeed(std::string& link,std::string& html,int depth=0,int max);
    URL pop();
    bool empty();
    std::string getLink();
    int getDepth();
    size_t getSize();
    void backup();
    
    
};