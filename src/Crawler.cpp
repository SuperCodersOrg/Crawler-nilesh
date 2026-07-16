#include "../include/Crawler.h"

Crawler::Crawler(){
    depth=2;
    normalizer.seedLink="empty";
}

// void Continue(){

// }

void Crawler::crawl(string seed,int deep=2){
    depth=deep;

    if(normalizer.isrelative(seed)){
        cout<<"Source link is invalid or relative"<<endl;
        return;
    }
    normalizer.seedLink = seed;

    frontier.put(seed, 0);
    size_t i=0;
    while(!frontier.empty()){
        cout<<"-------------------------------------------------------------\n";
        cout<<"-------------------------------------------------------------\n";
        cout<<"Next Url :"<<frontier.getLink()<<endl;
        cout<<"Depth: "<<frontier.getDepth()<<endl;
        cout<<"Count: "<<i<<endl;
       

        string link = frontier.getLink();
        int linkDepth = frontier.getDepth();
        frontier.pop();
        
        try{
            if(linkDepth > depth){ 
                cout<<"Depth Reached!\n";
                continue;
            }
            
            normalizer.normalize(link);
            if(link.empty()){
                continue;
            } 

            if(visited.exists(link)){
                cout << "Already visited\n" << link << endl;
                continue;
            }

            string html = fetch.getHtml(link);

            visited.insert(link);
           
           

            DynamicArray<string> links = htmlparser.parseHtml(html);
    
            for(int i = 0; i < links.size(); i++){
                normalizer.normalize(links[i]);
                if(!links[i].empty() && !visited.exists(links[i])){
                    frontier.put(links[i], linkDepth + 1);
                    
                }
            }
            pages.storePage(link,html,linkDepth);

            cout<<"Total links: "<<links.size()<<endl;
        }
        catch(const std::exception& e){
            cout << "Failed : " << link << endl;
            cout << e.what() << endl;
            continue;
        }
        i++;
    }
}

int main(){
    cout << "Main Started\n";

    Crawler c;

    cout << "Crawler Created\n";

    string input;
    int depth,size;

    // int choice;
    // cout<<"1. Continue crawler?\n2. Start from a seed link\n";
    // cin>>choice;
    // if(choice==1){

    //     cout << "Finished\n";

    // }
    // else if(choice ==2){
    // }
    // else{
    //     cout<<"You entered an invalid choice";
    // }
    
    cout<<"Enter a Seed link: ";
    cin>>input;
    cout<<"Enter MaxDepth: ";
    cin>>depth;
    c.crawl(input,depth);
    
    
    
    

}