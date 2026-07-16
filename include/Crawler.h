#pragma once
#include "Frontier.h"
#include "Normalizer.h"
#include "../CDP/CDPScraper.h"
#include "HtmlParser.h"
#include "PageStorage.h"



class Crawler{
    private:
    int depth;
    Set<string>visited;
    Frontier frontier;
    Normalizer normalizer;
    CDPScraper fetch;
    HtmlParser htmlparser;
    PageStorage pages;

    public:
    Crawler();
    void Continue();
    void crawl(string seed,int deep);


};