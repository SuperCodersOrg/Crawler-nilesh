#pragma once

#include <string>
#include "Database.h"



class PageStorage
{
private:
    Database d;

public:
    PageStorage();

    bool storePage(std::string &url,
                   std::string &html,
                   int depth);

    bool getPage(std::string &url,
                 int &depth,
                 std::string &html,
                 std::string &lastCrawl);

    std::string getHtml(std::string &url);
    
    int getDepth(std::string &url);

    std::string getLastURL();

    std::string getLastCrawl(std::string &url);
};