#include"Queue.h"
#include <string>

using namespace std;


class Frontier{

    struct URL{
        string link;
        string html;
        int depth;
        string lastCrawl;
        size_t id;
    };
    Queue<URL>url;
    void To_lower(string &link);
    void removeFragment(string & source);
    void normalizePath(string &source);

    public:
    string normalizer( string &source);
    string getHtml(string const &link);
    int getDepht(string const &link);
    string getLastCrawl(string const &link);
    void putUrl(string const &link,string const &html,string const &lastCrawl,int const &depth,size_t const id);

    // method overloading
    string normalizer(const size_t &id);
    string getHtml(const size_t &id);
    int getDepht(const size_t &id);
    string getLastCrawl(const size_t &id);
    
    size_t getId(string const &link);
};