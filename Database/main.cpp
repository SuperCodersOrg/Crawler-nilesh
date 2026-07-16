#include "../include/PageStorage.h"
#include <iostream>

using namespace std;

int main()
{
    PageStorage storage;

    string url = "https://example.com";
    string html = "<html><body>Hello World</body></html>";

    int depth = 0;
    int maxDepth = 2;

    cout << "\n========== PAGE INSERT ==========\n";

    if (storage.storePage(url, html, depth))
        cout << "Page Inserted Successfully\n";
    else
        cout << "Page Insert Failed\n";

    cout << "\n========== GET PAGE ==========\n";

    string fetchedHtml;
    string lastCrawl;
    int fetchedDepth;

    if (storage.getPage(url, fetchedDepth, fetchedHtml, lastCrawl))
    {
        cout << "URL        : " << url << endl;
        cout << "Depth      : " << fetchedDepth << endl;
        cout << "HTML       : " << fetchedHtml << endl;
        cout << "Last Crawl : " << lastCrawl << endl;
    }
    else
    {
        cout << "Page Not Found\n";
    }

    cout << "\n========== GET HTML ==========\n";
    cout << storage.getHtml(url) << endl;

    cout << "\n========== GET DEPTH ==========\n";
    cout << storage.getDepth(url) << endl;

    cout << "\n========== LAST URL ==========\n";
    cout << storage.getLastURL() << endl;

    cout << "\n========== LAST CRAWL ==========\n";
    cout << storage.getLastCrawl(url) << endl;

    cout << "\n========== FRONTIER ==========\n";

    storage.putFrontier(url, depth);

    string frontierUrl;
    int frontierDepth;

    storage.getFrontier(frontierUrl, frontierDepth);

    cout << "Frontier URL   : " << frontierUrl << endl;
    cout << "Frontier Depth : " << frontierDepth << endl;

    storage.deleteFrontier(frontierUrl, frontierDepth);

    cout << "Frontier Deleted\n";

    cout << "\n========== SEED ==========\n";

    storage.putSeed(url, html, depth, maxDepth);

    cout << "Seed Inserted Successfully\n";

    cout << "\n========== DONE ==========\n";

    return 0;
}