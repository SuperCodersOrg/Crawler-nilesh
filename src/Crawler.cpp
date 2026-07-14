#include "../include/Crawler.h"

Crawler::Crawler(){
    depth=2;
    normalizer.seedLink="empty";

}
void Crawler::crawl(string seed,int deep=0){
    if(deep>depth)return ;
    normalizer.normalize(seed);
    if(normalizer.seedLink=="empty"){
        if(normalizer.isrelative(seed)){
            cout<<"Source link is invalid or relative"<<endl;
            return ;
        }
        normalizer.seedLink=seed;
    }
    if(frontier.exists(seed)){
        return ;
    }
    frontier.put(seed,deep);
        
    string html=fetch.getHtml(seed);
    DynamicArray<string>links;
    links=htmlparser.parseHtml(html);
    for(int i=0;i<links.size();i++){
        normalizer.normalize(links[i]);
        if( !links[i].empty() && !frontier.exists(links[i])){
            frontier.put(links[i],deep+1);
            cout<<links[i]<<endl;
        }
    }
    frontier.pop();
    
    crawl(frontier.getLink(),frontier.getDepth());
    return ;
}

int main(){
    Crawler c;
    c.crawl("https://nileshsahu.in");
    
}