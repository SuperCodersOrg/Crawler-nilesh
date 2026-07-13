#include "../include/Frontier.h"
#include "../include/STL/DynamicArray.h"
#include<string>
#include<sstream>

// put(link and depth)
void Frontier::put(string & link,int deep){
    visited.insert(link);
    URL url;
    url.link=link;
    url.lastCrawl=getDate();
    url.depth=deep;
    queue.push(url);
}

// pop()
Frontier :: URL Frontier::pop(){
    return queue.pop();
}

// getLink()
string Frontier::getLink(){
    URL url;
    url=queue.front();
    return url.link;
}

// empty()
bool Frontier::empty(){
    return queue.empty();
}

// getDepth()
int Frontier::getDepth(){
    URL url;
    url=queue.front();
    return url.depth;
}

// getDate()
string Frontier:: getDate() {

    time_t now = time(NULL);
    tm *t = localtime(&now);

    char date[11];

    sprintf(date, "%04d-%02d-%02d",
            t->tm_year + 1900,
            t->tm_mon + 1,
            t->tm_mday);

    return date;
}




// exists()
bool Frontier::exists(string link){
    return visited.exists(link);
}

// int main(){
//     Frontier f;
//     string s="HTTP://Example.COM:80/a/./b/../c//index.html#abc";
//     cout<<"Input: "<<s<<endl;
//     cout<<"Output: "<<f.normalizer(s);
// }