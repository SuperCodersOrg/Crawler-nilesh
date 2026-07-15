#pragma once

#include <string>
#include <mysql.h>

class Database {
private:
    MYSQL *conn;

public:
    Database();
    ~Database();

    bool putRecord(std::string &url,
                   std::string &html,
                   int depth);

    bool get(const std::string &url,
             int &depth,
             std::string &html,
             std::string &lastCrawl);

    std::string getHtml(std::string &url);
    int getDepth(std::string &url);
    std::string getLastCrawl(std::string &url);
};
