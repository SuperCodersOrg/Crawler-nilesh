#include "STL/DynamicArray.h"
#include<string>
using namespace std;

class HtmlParser{
    private:
    DynamicArray<string>links;
    public:
    size_t parseHttp(string part);
    size_t parseHref(string part);
    DynamicArray<string>parseHtml(string html);

};

