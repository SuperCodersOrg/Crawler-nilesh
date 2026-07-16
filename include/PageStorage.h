#pragma once

#include <string>
#include "Database.h"

using namespace std;

class PageStorage
{
private:
    Database d;

public:
    PageStorage();

    bool storePage(string &url,
                   string &html,
                   int depth);

    bool getPage(string &url,
                 int &depth,
                 string &html,
                 string &lastCrawl);

    string getHtml(string &url);
    
    int getDepth(string &url);

    string getLastCrawl(string &url);
};