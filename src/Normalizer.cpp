#include "../include/Normalizer.h"
#include<string>
#include<sstream>



// To_lower()
void Normalizer::To_lower(string &link){
    for(char &c:link){
        if(c>= 'A' && c<='Z'){
            c=c-'A'+'a';
        }
    }
    
};

// Normalizer()
Normalizer::Normalizer(){
    ignoreDomain.insert("drive.google.com");
    ignoreDomain.insert("youtube.com");
    ignoreDomain.insert("twitter.com");
    ignoreDomain.insert("x.com");
    ignoreDomain.insert("facebook.com");
    ignoreDomain.insert("instagram.com");
    ignoreDomain.insert("tiktok.com");
    ignoreDomain.insert("snapchat.com");
    ignoreDomain.insert("pinterest.com");
    ignoreDomain.insert("reddit.com");
}


// removeFragment()
void Normalizer::removeFragment(string &source){
    size_t pos=source.find('#');
    if(pos==string::npos) return ;
    source=source.substr(0,pos);    
}

// normalizePath()
void Normalizer::normalizePath(string &source){
    DynamicArray<string>content;
    string token;
    stringstream ss(source);
    while(getline(ss,token,'/')){
        if(token.empty() || token==".")continue;

        if(token==".."){
            if(content.size()!=0){
                content.pop_back();
            }
            continue;
        }
        content.push_back(token);
    }
    string result="/";
    for(int i=0;i<content.size();i++){
        result=result+ content[i]+'/';
    }
    source=result;
}

// isrelative()
bool Normalizer::isrelative(string & source){
    size_t schemePos=source.find("://");
    if(schemePos==string::npos){
        return true;
    }
    return false;

}

//string normalizer()
string Normalizer::normalize(string &source){
    To_lower(source);
    
    
    // relative url hai
    if(isrelative(source)){
        relativeURL(source);   
    }
    
    removeFragment(source);
    

    
    size_t schemePos=source.find("://"); 
    
    string scheme = source.substr(0,schemePos);
    string remaining = source.substr(schemePos+3);

    size_t slashPos=remaining.find('/');
    if(slashPos==string::npos)return "null";

    string authority=remaining.substr(0,slashPos);
    string path =remaining.substr(slashPos);

    size_t dotPos=authority.find(':');
    if(dotPos!=string::npos){
        string port=authority.substr(dotPos+1);
        string host=authority.substr(0,dotPos);

        if((port=="80" && scheme=="http")||(port=="443" && scheme == "https")){
            authority=host;
        }
    }
    normalizePath(path);

    return scheme + "://" + authority + path;
}


// relativeURL
void Normalizer::relativeURL(string & source){
    if(seedLink=="empty"){
        cout<<"Seed link is not valid or relative";
        return ;
    }
    if(source[0]=='/')source=source.substr(1,source.size()-1);
    source=seedLink+source;
    
   

}

// DynamicArray<string> normalizer()
DynamicArray<string> Normalizer::normalize(DynamicArray<string> &source){
    DynamicArray<string>normalisedlink;

    for(int i=0;i<source.size();i++){

        To_lower(source[i]);
    
        removeFragment(source[i]);
    
        size_t schemePos=source[i].find("://"); 
        
        if(schemePos==string::npos){
            continue;
        }
    
        string scheme = source[i].substr(0,schemePos);
        string remaining = source[i].substr(schemePos+3);
    
        size_t slashPos=remaining.find('/');
        if(slashPos==string::npos){
            continue;
        }
    
        string authority=remaining.substr(0,slashPos);
        string path =remaining.substr(slashPos);
    
        size_t dotPos=authority.find(':');
        if(dotPos!=string::npos){
            string port=authority.substr(dotPos+1);
            string host=authority.substr(0,dotPos);
    
            if((port=="80" && scheme=="http")||(port=="443" && scheme == "https")){
                authority=host;
            }
        }
        normalizePath(path);

        normalisedlink.push_back(scheme + "://" + authority + path);
    
    }
    return normalisedlink;
}


