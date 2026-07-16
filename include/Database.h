#pragma once

#include <string>
#include <mysql.h>

class Database {
private:

    MYSQL *conn;
public:
    Database();
    ~Database();

    bool putPagesRecord(std::string &url,
                   std::string &html,
                   int depth);

    bool getPages(const std::string &url,
             int &depth,
             std::string &html,
             std::string &lastCrawl);
    std::string getPagesHtml(std::string &url);
    int getPagesDepth(std::string &url);
    std::string getPagesLastCrawl(std::string &url);
    std::string getPagesLastUrl();

    bool putFrontier(std::string url,int depth);
    bool deleteFrontier(std::string url,int depth);
    void getFrontier(std::string &url,int &depth);

    void putSeed(std::string &url,std::string& html,int &depth,int & max);

};
