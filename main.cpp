#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class URLNormalizer {
public:

    static string toLower(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    }

    static string removeFragment(string url) {
        size_t pos = url.find('#');
        if (pos != string::npos)
            return url.substr(0, pos);
        return url;
    }

    static string normalizePath(string path) {

        vector<string> parts;
        string token;
        stringstream ss(path);

        while (getline(ss, token, '/')) {

            if (token.empty() || token == ".")
            
                continue;

            if (token == "..") {

                if (!parts.empty())
                    parts.pop_back();

            } else {

                parts.push_back(token);
            }
        }

        string result = "/";

        for (size_t i = 0; i < parts.size(); i++) {

            result += parts[i];

            if (i != parts.size() - 1)
                result += "/";
        }

        

        return result;
    }

    static string normalize(string url) {

        url = removeFragment(url);

        size_t schemePos = url.find("://");

        if (schemePos == string::npos)
            return url;

        string scheme = toLower(url.substr(0, schemePos));

        string remaining = url.substr(schemePos + 3);

        size_t slashPos = remaining.find('/');

        string authority;
        string path;

        if (slashPos == string::npos) {
            authority = remaining;
            path = "/";
        }
        else {
            authority = remaining.substr(0, slashPos);
            path = remaining.substr(slashPos);
        }

        authority = toLower(authority);

        size_t colonPos = authority.find(':');

        if (colonPos != string::npos) {

            string host = authority.substr(0, colonPos);
            string port = authority.substr(colonPos + 1);

            if ((scheme == "http" && port == "80") ||
                (scheme == "https" && port == "443")) {

                authority = host;
            }
        }

        path = normalizePath(path);

        return scheme + "://" + authority + path;
    }
};

int main() {

    vector<string> tests = {

        "HTTP://Example.COM:80/a/./b/../c//index.html#abc",
        "https://GOOGLE.com:443/",
        "http://google.com////a///b",
        "http://example.com"
    };

    for (auto &u : tests)
        cout << URLNormalizer::normalize(u) << endl;
    
}