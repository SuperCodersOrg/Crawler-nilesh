#include "../include/Database.h"
#include <cstring>
#include <iostream>

using namespace std;

// constructor()
Database::Database() {
    conn = mysql_init(nullptr);

    if (conn == nullptr) {
        cout << "mysql_init() failed" << endl;
        return;
    }

    if (!mysql_real_connect(
            conn,
            "localhost",
            "root",
            "Nilesh@mysql2005",
            "webcrawler",
            3306,
            nullptr,
            0))
    {
        cout << "Connection Failed" << endl;
        cout << mysql_error(conn) << endl;
        mysql_close(conn);
        conn = nullptr;
        return;
    }

    cout << "Database Connected Successfully" << endl;
}

bool Database::putFrontier(string url, int depth)
{
    std::string query =
        "INSERT INTO frontier(url, depth) VALUES('" +
        url + "', " + std::to_string(depth) + ");";

    if (mysql_query(conn, query.c_str()))
    {
        std::cout << "Error inserting into frontier: "
                  << mysql_error(conn) << std::endl;
        return false;
    }

    return true;
}

void Database::getFrontier(string &url,int &depth){
    string query="select * from frontier order by id desc LIMIT 1";
    if(mysql_query(conn,query.c_str())){
        cout<<"Error in getting Last Url: "<<mysql_error(conn)<<endl;
    }
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == nullptr)
        return ;

    MYSQL_ROW row = mysql_fetch_row(result);
    if (row == nullptr) {
        mysql_free_result(result);
        return ;
    }

    url=row[0];
    depth=stoi(row[1]);
    return ;
}


bool Database::deleteFrontier(string url, int depth)
{
    std::string query =
        "DELETE FROM frontier where url = '" +
        url + "' and depth = " + std::to_string(depth) + " ;";

    if (mysql_query(conn, query.c_str()))
    {
        std::cout << "Error inserting into frontier: "
                  << mysql_error(conn) << std::endl;
        return false;
    }

    return true;
}

// putRecord()
bool Database::putPagesRecord(string &url,
                         string &html,
                         int depth)
{
    const char *query =
        "INSERT INTO pages(url, depth, html) VALUES(?, ?, ?)";

    MYSQL_STMT *stmt = mysql_stmt_init(conn);

    if (stmt == nullptr)
    {
        cout << "Statement initialization failed" << endl;
        return false;
    }

    if (mysql_stmt_prepare(stmt, query, strlen(query)))
    {
        cout << "Prepare Error : "
             << mysql_stmt_error(stmt) << endl;

        mysql_stmt_close(stmt);
        return false;
    }

    MYSQL_BIND bind[3];
    memset(bind, 0, sizeof(bind));

    unsigned long urlLength = url.length();
    unsigned long htmlLength = html.length();

    // URL
    bind[0].buffer_type = MYSQL_TYPE_STRING;
    bind[0].buffer = (char *)url.c_str();
    bind[0].buffer_length = urlLength;
    bind[0].length = &urlLength;

    // Depth
    bind[1].buffer_type = MYSQL_TYPE_LONG;
    bind[1].buffer = &depth;

    // HTML
    bind[2].buffer_type = MYSQL_TYPE_STRING;
    bind[2].buffer = (char *)html.c_str();
    bind[2].buffer_length = htmlLength;
    bind[2].length = &htmlLength;

    if (mysql_stmt_bind_param(stmt, bind))
    {
        cout << "Bind Error : "
             << mysql_stmt_error(stmt) << endl;

        mysql_stmt_close(stmt);
        return false;
    }

    if (mysql_stmt_execute(stmt))
    {
        cout << "Execute Error : "
             << mysql_stmt_error(stmt) << endl;

        mysql_stmt_close(stmt);
        return false;
    }

    mysql_stmt_close(stmt);

    return true;
}

// getLastUrl()
string Database::getPagesLastUrl(){
    string query="SELECT url FROM pages ORDER BY id DESC LIMIT 1";
    if(mysql_query(conn,query.c_str())){
        cout<<"Error in getting Last Url: "<<mysql_error(conn)<<endl;
    }
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == nullptr)
        return "null";

    MYSQL_ROW row = mysql_fetch_row(result);
    if (row == nullptr) {
        mysql_free_result(result);
        return "null";
    }

    string url=row[0];

    mysql_free_result(result);

    return url;
}




// get()
bool Database::getPages(const string &url,
                   int &depth,
                   string &html,
                   string &lastCrawl)
{
    string query =
        "SELECT depth, html, last_crawl FROM pages WHERE url='"
        + url +
        "' LIMIT 1";

    if (mysql_query(conn, query.c_str())) {
        cout << "Select Error : " << mysql_error(conn) << endl;
        return false;
    }

    MYSQL_RES *result = mysql_store_result(conn);

    if (result == nullptr)
        return false;

    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == nullptr) {
        mysql_free_result(result);
        return false;
    }

    depth = row[0] ? stoi(row[0]) : 0;
    html = row[1] ? row[1] : "";
    lastCrawl = row[2] ? row[2] : "";

    mysql_free_result(result);

    return true;
}

// getHtml()
string Database::getPagesHtml(string &url)
{
    string html;
    string last;
    int depth;

    if (!getPages(url, depth, html, last))
        return "";

    return html;
}

int Database::getPagesDepth(string &url)
{
    string html, last;
    int depth = -1;

    if (!getPages(url, depth, html, last))
        return -1;

    return depth;
}


// getLastCrawl()
string Database::getPagesLastCrawl(string &url)
{
    string html;
    string last;
    int depth;

    if (!getPages(url, depth, html, last))
        return "";

    return last;
}

void Database::putSeed(std::string &link,
                       std::string& html,
                       int &depth,
                       int &max)
{
    const char *query =
        "INSERT INTO seeds(url, max_depth, html) VALUES(?, ?, ?)";

    MYSQL_STMT *stmt = mysql_stmt_init(conn);

    if (stmt == nullptr)
    {
        std::cout << "Statement initialization failed\n";
        return;
    }

    if (mysql_stmt_prepare(stmt, query, strlen(query)))
    {
        std::cout << "Prepare Error : "
                  << mysql_stmt_error(stmt) << std::endl;

        mysql_stmt_close(stmt);
        return;
    }

    MYSQL_BIND bind[3];
    memset(bind, 0, sizeof(bind));

    unsigned long urlLength = link.length();
    unsigned long htmlLength = html.length();

    // URL
    bind[0].buffer_type = MYSQL_TYPE_STRING;
    bind[0].buffer = (char *)link.c_str();
    bind[0].buffer_length = urlLength;
    bind[0].length = &urlLength;

    // Max Depth
    bind[1].buffer_type = MYSQL_TYPE_LONG;
    bind[1].buffer = &max;

    // HTML
    bind[2].buffer_type = MYSQL_TYPE_STRING;
    bind[2].buffer = (char *)html.c_str();
    bind[2].buffer_length = htmlLength;
    bind[2].length = &htmlLength;

    if (mysql_stmt_bind_param(stmt, bind))
    {
        std::cout << "Bind Error : "
                  << mysql_stmt_error(stmt) << std::endl;

        mysql_stmt_close(stmt);
        return;
    }

    if (mysql_stmt_execute(stmt))
    {
        std::cout << "Execute Error : "
                  << mysql_stmt_error(stmt) << std::endl;

        mysql_stmt_close(stmt);
        return;
    }

    mysql_stmt_close(stmt);
}

Database::~Database()
{
    if (conn)
        mysql_close(conn);
}