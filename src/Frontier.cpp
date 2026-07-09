#include "../include/Frontier.h"
#include "../include/STL/DynamicArray.h"
#include<string>
#include<sstream>

// To_lower()
void Frontier::To_lower(string &link){
    for(char &c:link){
        if(c>= 'A' && c<='Z'){
            c=c-'A'+'a';
        }
    }
    
};

// removeFragment()
void Frontier::removeFragment(string &source){
    size_t pos=source.find('#');
    if(pos==string::npos) return ;
    source=source.substr(0,pos);    
}

// normalizePath()
void Frontier::normalizePath(string &source){
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


//normalizer()
string Frontier::normalizer(string &source){
    To_lower(source);

    removeFragment(source);

    size_t schemePos=source.find("://"); 
    
    if(schemePos==string::npos)return "null";

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

int main(){
    Frontier f;
    string s="HTTP://Example.COM:80/a/./b/../c//index.html#abc";
    cout<<"Input: "<<s<<endl;
    cout<<"Output: "<<f.normalizer(s);
}