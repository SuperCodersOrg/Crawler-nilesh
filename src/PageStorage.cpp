#include "../include/PageStorage.h"

PageStorage::PageStorage()
{
}

bool PageStorage::storePage(string &url,
                            string &html,
                            int depth)
{
    return d.putRecord(url, html, depth);
}

bool PageStorage::getPage(string &url,
                          int &depth,
                          string &html,
                          string &lastCrawl)
{
    return d.get(url, depth, html, lastCrawl);
}

string PageStorage::getHtml(string &url)
{
    return d.getHtml(url);
}

int PageStorage::getDepth(string &url)
{
    return d.getDepth(url);
}

string PageStorage::getLastCrawl(string &url)
{
    return d.getLastCrawl(url);
}