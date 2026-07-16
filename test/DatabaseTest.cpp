#include <gtest/gtest.h>
#include "../include/Database.h"

class DatabaseTest : public ::testing::Test
{
protected:
    Database db;

    std::string url;
    std::string html;
    int depth;

    void SetUp() override
    {
        url = "https://example.com";
        html = "<html><body>Hello World</body></html>";
        depth = 3;

        db.putRecord(url, html, depth);
    }

    void TearDown() override
    {
        // Optional
        // Delete inserted record if delete functionality exists.
    }
};

TEST_F(DatabaseTest, PutRecord)
{
    std::string url2 = "https://google.com";
    std::string html2 = "<html>Google</html>";

    EXPECT_TRUE(db.putRecord(url2, html2, 1));
}

TEST_F(DatabaseTest, GetExistingRecord)
{
    int fetchedDepth;
    std::string fetchedHtml;
    std::string lastCrawl;

    EXPECT_TRUE(
        db.get(
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

TEST_F(DatabaseTest, GetHtml)
{
    EXPECT_EQ(
        html,
        db.getHtml(url)
    );
}

TEST_F(DatabaseTest, GetDepth)
{
    EXPECT_EQ(
        depth,
        db.getDepth(url)
    );
}

TEST_F(DatabaseTest, GetLastCrawl)
{
    EXPECT_FALSE(
        db.getLastCrawl(url).empty()
    );
}

TEST_F(DatabaseTest, GetNonExistingRecord)
{
    std::string invalidUrl = "https://doesnotexist.com";

    int fetchedDepth;
    std::string fetchedHtml;
    std::string lastCrawl;

    EXPECT_FALSE(
        db.get(
            invalidUrl,
            fetchedDepth,
            fetchedHtml,
            lastCrawl
        )
    );
}

TEST_F(DatabaseTest, GetHtmlForInvalidURL)
{
    std::string invalidUrl = "https://xyz123456.com";

    EXPECT_EQ(
        "",
        db.getHtml(invalidUrl)
    );
}

TEST_F(DatabaseTest, GetDepthForInvalidURL)
{
    std::string invalidUrl = "https://xyz123456.com";

    EXPECT_EQ(
        -1,
        db.getDepth(invalidUrl)
    );
}

TEST_F(DatabaseTest, GetLastCrawlForInvalidURL)
{
    std::string invalidUrl = "https://xyz123456.com";

    EXPECT_EQ(
        "",
        db.getLastCrawl(invalidUrl)
    );
}

TEST_F(DatabaseTest, MultipleInsertions)
{
    for(int i = 0; i < 10; i++)
    {
        std::string url =
            "https://site" + std::to_string(i) + ".com";

        std::string html =
            "<html>" + std::to_string(i) + "</html>";

        EXPECT_TRUE(
            db.putRecord(
                url,
                html,
                i
            )
        );
    }
}