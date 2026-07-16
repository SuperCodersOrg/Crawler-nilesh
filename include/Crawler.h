#pragma once
#include "Frontier.h"
#include "Normalizer.h"
#include "../CDP/CDPScraper.h"
#include "HtmlParser.h"
#include "PageStorage.h"



class Crawler{
    private:
    int depth;
    Set<std::string>visited;
    Frontier frontier;
    Normalizer normalizer;
    CDPScraper fetch;
    HtmlParser htmlparser;
    PageStorage pages;

    public:
    Crawler();
    void Continue();
    void crawl(std::string seed,int deep);


};