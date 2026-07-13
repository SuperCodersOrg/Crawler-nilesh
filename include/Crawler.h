#pragma once
#include "Frontier.h"
#include "Normalizer.h"
#include "../CDP/CDPScraper.h"
#include "HtmlParser.h"



class Crawler{
    private:
    int depth;
    Frontier frontier;
    Normalizer normalizer;
    CDPScraper fetch;
    HtmlParser htmlparser;

    public:
    Crawler();
    void crawl(string seed,int deep);


};