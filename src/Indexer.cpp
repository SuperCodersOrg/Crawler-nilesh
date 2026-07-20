#include "../include/Indexer.h"
#include <cctype>
#include <iostream>
#include <sstream>

using namespace std;


Indexer::Indexer()
{
}

Indexer::~Indexer()
{
}

void Indexer::buildIndex()
{
    int maxId = storage.getMaxPageId();

    std::cout << "Building Index..." << std::endl;
    std::cout << "Total Pages : " << maxId << std::endl;

    for (int id = 1; id <= maxId; id++)
    {
        string html = storage.getHtml(id);
        string url = storage.getUrl(id);

        if (html.empty())
            continue;

        
        

        countWords(html,url);

        //storeIndex(id, frequency);

        std::cout << "Indexed Page : " << id << std::endl;
    }
    
    DynamicArray<string>array=frequency.getkeys();
    for(int i=0;i<array.size();i++){
        int freq=frequency.get(array[i])[0].freq;
        cout<<"key: "<<array[i]<<" -> "<<freq<<endl;

    }
    string name;

    cout<<"------------------------------------------------------\n";
    cout<<"Enter key: ";
    cin>>name;
    cout<<frequency.get(name)[0].freq<<" -> "<<frequency.get(name)[0].link<<endl;
    cout<<frequency.get(name)[1].freq<<" -> "<<frequency.get(name)[1].link<<endl;
    cout<<frequency.get(name)[2].freq<<" -> "<<frequency.get(name)[2].link<<endl;


    std::cout << "Indexing Completed." << std::endl;
}

std::string Indexer::normalizeWord(const std::string& word)
{
    std::string normalized;

    for (char ch : word)
    {
        unsigned char c = static_cast<unsigned char>(ch);

        // alphabets aur digits
        if (std::isalnum(c))
        {
            normalized += std::tolower(c);
        }
    }

    return normalized;
}

void Indexer:: countWords(const std::string& html,string & link){
     stringstream ss(html);

     HashMap<string,int>pageFrequency;

     string word;
     while(ss>>word){
        word = normalizeWord(word);
        if(word.empty())continue;
        if(pageFrequency.exists(word)){
            int size=pageFrequency.get(word);
            size++;
            pageFrequency.insert(word,size);
            continue;
        }
        pageFrequency.insert(word,1);
    }

    DynamicArray<string>keys=pageFrequency.getkeys();
    for(int i=0;i<keys.size();i++){
        if(!frequency.exists(keys[i])){
            Url url;
            url.freq=pageFrequency.get(keys[i]);
            url.link=link;
            DynamicArray<Url>u;
            u.push_back(url);
            frequency.insert(keys[i],u);
            
        }
        else{
            DynamicArray<Url>rank=frequency.get(keys[i]);
            int pagekey=pageFrequency.get(keys[i]);
            bool inserted=false;
            Url greater;
            greater.freq=pagekey;
            greater.link=link;

            for(int j=0;j<rank.size();j++){
                if(pagekey > rank[j].freq){
                    rank.insert(j,greater);
                    if(rank.size()>5){
                        rank.pop_back();
                    }
                    inserted=true;
                    break;
                }

            }
            if(!inserted){
                if(rank.size()<5){
                    rank.push_back(greater);
                }
            }
            frequency.insert(keys[i],rank);
        }

    }
    
}

int main(){
    Indexer index;
    index.buildIndex();
     

}