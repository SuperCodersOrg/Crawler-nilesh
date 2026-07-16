#pragma once

#include <string>
#include <mysql.h>

class PageStorage
{
private:
    MYSQL *conn;

public:
    PageStorage();
    ~PageStorage();

    // Pages Table
    bool storePage(std::string &url,
                   std::string &html,
                   int depth,
                   int id);

    bool getPage(const std::string &url,
                 int &depth,
                 std::string &html,
                 std::string &lastCrawl);

    std::string getHtml(std::string &url);

    int getDepth(std::string &url);

    std::string getLastCrawl(std::string &url);

    std::string getLastFrontier(std::string &url,int &deep,int& id,int &max);

    // Frontier Table
    bool putFrontier(std::string url,
                     int depth,int max,int Id);

    bool deleteFrontier(std::string url,
                        int depth);

    bool clearFrontier();

    void getFrontier(std::string &url,
                     int &depth);

                     // Seeds Table
    size_t putSeeds(std::string &url,
                 std::string &html,
                 int &depth,
                 int &max);
};