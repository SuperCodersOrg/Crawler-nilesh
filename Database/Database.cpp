#include "../include/Database.h"
#include <cstring>
#include <iostream>

using namespace std;

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

bool Database::putRecord(string &url,
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

bool Database::get(const string &url,
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

string Database::getHtml(string &url)
{
    string html;
    string last;
    int depth;

    if (!get(url, depth, html, last))
        return "";

    return html;
}

int Database::getDepth(string &url)
{
    string html, last;
    int depth = -1;

    if (!get(url, depth, html, last))
        return -1;

    return depth;
}


string Database::getLastCrawl(string &url)
{
    string html;
    string last;
    int depth;

    if (!get(url, depth, html, last))
        return "";

    return last;
}

Database::~Database()
{
    if (conn)
        mysql_close(conn);
}