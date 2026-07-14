#include "../include/Crawler.h"

Crawler::Crawler(){
    depth=2;
    normalizer.seedLink="empty";

}
void Crawler::crawl(string seed,int deep=0){
    cout<<"Function calling "<<deep<<endl;
    if(deep>depth)return ;
    cout<<"Deep>depth false"<<endl;
    cout<<"Before normalise(seed)"<<endl;
    normalizer.normalize(seed);
    cout<<"After normalise(seed)"<<endl;
    if(normalizer.seedLink=="empty"){
        if(normalizer.isrelative(seed)){
            cout<<"Source link is invalid or relative"<<endl;
            return ;
        }
        normalizer.seedLink=seed;
    }
    cout<<"After if"<<endl;
    cout << "Checking: " << seed << endl;

    if(visited.exists(seed)){
        cout << "Already visited \n"<<seed;
        return;
    }

    cout << "Not visited\n";
    cout<<"After exists"<<endl;
    frontier.put(seed,deep);
    cout<<"Before Fectch"<<endl;
    string html=fetch.getHtml(seed);
    visited.insert(seed);
    cout<<"After Fectch"<<endl;
    DynamicArray<string>links;
    links=htmlparser.parseHtml(html);
    for(int i=0;i<links.size();i++){
        normalizer.normalize(links[i]);
        if( !links[i].empty() && !visited.exists(links[i])){
            frontier.put(links[i],deep+1);
            cout<<links[i]<<endl;
        }
    }
    frontier.pop();
    cout<<"Next URl"<<endl;
    cout<<frontier.getLink()<<" -> "<<frontier.getDepth()<<endl;
    crawl(frontier.getLink(),frontier.getDepth());
    return ;
}

int main(){
    Crawler c;
    c.crawl("https://nileshsahu.in");
    
}