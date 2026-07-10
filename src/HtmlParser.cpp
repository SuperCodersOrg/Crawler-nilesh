#include"../include/HtmlParser.h"
#include<iostream>
using namespace std;

size_t HtmlParser ::parseHttp(string html){
    size_t index=0;
    while(index<html.size()){
        if(html[index]=='\''){
            links.push_back(html.substr(0,index));
            return index;
        }
        if(html[index]=='"'){
            links.push_back(html.substr(0,index));
            return index;
        }
        if(html[index]==')'){
            links.push_back(html.substr(0,index));
            return index;
        }
        index++;
    }
    cout<<"Http error at size:------------"<<html.size();
    
    return 1;
}

size_t HtmlParser::parseHref(string html){
    size_t index=4;
    cout<<"Hit Href"<<endl;
    while(index<html.size()){
        if(html[index]==' '){
            index++;
            continue;
        }
        if(html[index]=='='){
            index++;
            continue;
        }
        if(html[index]=='"' || html[index]=='\''){
            index++;
            size_t first =index;
            while(index<html.size()){
                if(html[index]=='"' || html[index]=='\'' || html[index]==')'){
                    
                    links.push_back(html.substr(first,index-first));
                    return index;
                }
                index++;
            }
            return index;
        }
        index++;
    }
    cout<<"Herf error at size:"<<html.size()<<endl;
    cout<<html.substr(0,50)<<endl;
    return 1;

}

DynamicArray<string> HtmlParser::parseHtml(string html){
    size_t index=0;
    cout<<"hit http---------"<<endl;
    while(index<html.size()){
        if(html.substr(index,4)=="href"){
    
            index=index+parseHref(html.substr(index));
            continue;
        }
        
        if(html.substr(index,4)=="http"){
    
            index=index+parseHttp(html.substr(index));
            continue;
        }
        index++;
        // delete it
        
    }
    return links;
}