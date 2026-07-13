#include <iostream>
#include <ctime>

using namespace std;

string getDate() {

    time_t now = time(NULL);
    tm *t = localtime(&now);

    char date[11];

    sprintf(date, "%04d-%02d-%02d",
            t->tm_year + 1900,
            t->tm_mon + 1,
            t->tm_mday);

    return date;
}

int main() {

    cout << getDate();

    return 0;
}