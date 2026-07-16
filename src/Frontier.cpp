#include "../include/Frontier.h"
#include "../include/STL/DynamicArray.h"
#include<string>
#include<sstream>

using namespace std;

// put(link and depth)
void Frontier::put(string & link,int deep){
    URL url;
    url.link=link;
    url.depth=deep;
    database.putFrontier(link,deep);
    queue.push(url);
}
// put(link,depth and maxDepth)
void Frontier::putSeed(string & link,string & html,int deep=0,int max){
    URL url;
    url.link=link;
    url.depth=deep;
    queue.push(url);
    database.putSeed(link,html,deep,max);  
    
}

// pop()
Frontier :: URL Frontier::pop(){
    URL url=queue.front();
    string link=url.link;
    int depth=url.depth;
    database.deleteFrontier(link,depth);
    return queue.pop();

}

void Frontier::backup(){
    string link;
    int depth;
    database.getFrontier(link,depth);
    while(link!="null"){
        URL url;
        url.depth=depth;
        url.link=link;
        queue.push(url);
        database.getFrontier(link,depth);
    }

}

// getLink()
string Frontier::getLink(){
    URL url;
    url=queue.front();
    return url.link;
}
// getLink()
size_t Frontier::getSize(){
    return queue.size();
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


// int main(){
//     Frontier f;
//     string s="HTTP://Example.COM:80/a/./b/../c//index.html#abc";
//     cout<<"Input: "<<s<<endl;
//     cout<<"Output: "<<f.normalizer(s);
// }