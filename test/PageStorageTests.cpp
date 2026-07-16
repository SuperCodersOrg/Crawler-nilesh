#include <gtest/gtest.h>
#include "../include/PageStorage.h"

class PageStorageTest : public ::testing::Test
{
protected:
    PageStorage storage;

    std::string url;
    std::string html;
    int depth;

    void SetUp() override
    {
        url = "https://example.com";
        html = "<html><body>Hello World</body></html>";
        depth = 2;

        storage.storePage(url, html, depth);
    }
};

TEST_F(PageStorageTest, StorePage)
{
    std::string url = "https://google.com";
    std::string html = "<html>Google</html>";

    EXPECT_TRUE(storage.storePage(url, html, 1));
}

TEST_F(PageStorageTest, GetPage)
{
    int fetchedDepth;
    std::string fetchedHtml;
    std::string lastCrawl;

    EXPECT_TRUE(
        storage.getPage(
            url,
            fetchedDepth,
            fetchedHtml,
            lastCrawl
        )
    );

    EXPECT_EQ(depth, fetchedDepth);
    EXPECT_EQ(html, fetchedHtml);
    EXPECT_FALSE(lastCrawl.empty());
}

TEST_F(PageStorageTest, GetHtml)
{
    EXPECT_EQ(
        html,
        storage.getHtml(url)
    );
}

TEST_F(PageStorageTest, GetDepth)
{
    EXPECT_EQ(
        depth,
        storage.getDepth(url)
    );
}

TEST_F(PageStorageTest, GetLastCrawl)
{
    EXPECT_FALSE(
        storage.getLastCrawl(url).empty()
    );
}

TEST_F(PageStorageTest, InvalidPageLookup)
{
    std::string invalid = "https://doesnotexist.com";

    int fetchedDepth;
    std::string fetchedHtml;
    std::string lastCrawl;

    EXPECT_FALSE(
        storage.getPage(
            invalid,
            fetchedDepth,
            fetchedHtml,
            lastCrawl
        )
    );
}

TEST_F(PageStorageTest, InvalidHtml)
{
    std::string invalid = "https://doesnotexist.com";

    EXPECT_EQ(
        "",
        storage.getHtml(invalid)
    );
}

TEST_F(PageStorageTest, InvalidDepth)
{
    std::string invalid = "https://doesnotexist.com";

    EXPECT_EQ(
        -1,
        storage.getDepth(invalid)
    );
}

TEST_F(PageStorageTest, InvalidLastCrawl)
{
    std::string invalid = "https://doesnotexist.com";

    EXPECT_EQ(
        "",
        storage.getLastCrawl(invalid)
    );
}

TEST_F(PageStorageTest, MultiplePages)
{
    for(int i = 0; i < 10; i++)
    {
        std::string url =
            "https://page" + std::to_string(i) + ".com";

        std::string html =
            "<html>" + std::to_string(i) + "</html>";

        EXPECT_TRUE(
            storage.storePage(
                url,
                html,
                i
            )
        );
    }
}