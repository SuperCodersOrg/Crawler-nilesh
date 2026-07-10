#include"Queue.h"
#include"Set.h"
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
    set<string>visited;
    
    void To_lower(string &link);
    void removeFragment(string & source);
    void normalizePath(string &source);

    public:
    DynamicArray<string> normalizer(DynamicArray<string> &source);
    void putUrl(string const &link,string const &html,string const &lastCrawl,int const &depth,size_t const id);
    size_t getId(string const &link);
    
    string normalizer(string &source);
    string getHtml(string const &link);
    int getDepht(string const &link);
    string getLastCrawl(string const &link);
    
};