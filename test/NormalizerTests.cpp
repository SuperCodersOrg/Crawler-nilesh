#include <gtest/gtest.h>
#include "../include/Normalizer.h"

class NormalizerTest : public ::testing::Test
{
protected:
    Normalizer normalizer;
};

TEST_F(NormalizerTest, RelativeURL)
{
    std::string url = "/about";

    EXPECT_TRUE(normalizer.isrelative(url));
}

TEST_F(NormalizerTest, AbsoluteURL)
{
    std::string url = "https://example.com";

    EXPECT_FALSE(normalizer.isrelative(url));
}

TEST_F(NormalizerTest, LowerCaseNormalization)
{
    std::string url = "HTTPS://GOOGLE.COM/ABC";

    normalizer.normalize(url);

    EXPECT_EQ(
        "https://google.com/abc/",
        url
    );
}

TEST_F(NormalizerTest, RemoveFragment)
{
    std::string url =
        "https://example.com/page#section";

    normalizer.normalize(url);

    EXPECT_EQ(
        "https://example.com/page/",
        url
    );
}

TEST_F(NormalizerTest, RemoveDefaultHTTPPort)
{
    std::string url =
        "http://example.com:80/index.html";

    normalizer.normalize(url);

    EXPECT_EQ(
        "http://example.com/index.html/",
        url
    );
}

TEST_F(NormalizerTest, RemoveDefaultHTTPSPort)
{
    std::string url =
        "https://example.com:443/index.html";

    normalizer.normalize(url);

    EXPECT_EQ(
        "https://example.com/index.html/",
        url
    );
}

TEST_F(NormalizerTest, IgnoreMailTo)
{
    normalizer.seedLink = "https://example.com";

    std::string url = "mailto:test@gmail.com";

    normalizer.normalize(url);

    EXPECT_EQ("", url);
}

TEST_F(NormalizerTest, IgnoreJavascript)
{
    normalizer.seedLink = "https://example.com";

    std::string url = "javascript:void(0)";

    normalizer.normalize(url);

    EXPECT_EQ("", url);
}

TEST_F(NormalizerTest, RelativeConversion)
{
    normalizer.seedLink = "https://example.com";

    std::string url = "contact";

    normalizer.normalize(url);

    EXPECT_EQ(
        "https://example.com/contact/",
        url
    );
}

TEST_F(NormalizerTest, RelativeRootConversion)
{
    normalizer.seedLink = "https://example.com";

    std::string url = "/about";

    normalizer.normalize(url);

    EXPECT_EQ(
        "https://example.com/about/",
        url
    );
}

TEST_F(NormalizerTest, IgnoreInvalidAuthority)
{
    std::string url =
        "https://exa*mple.com/page";

    normalizer.normalize(url);

    EXPECT_EQ("", url);
}

TEST_F(NormalizerTest, NormalizeDynamicArray)
{
    DynamicArray<std::string> links;

    links.push_back("HTTP://GOOGLE.COM:80/ABC");
    links.push_back("HTTPS://OPENAI.COM:443/TEST");

    DynamicArray<std::string> result =
        normalizer.normalize(links);

    ASSERT_EQ(result.size(),2);

    EXPECT_EQ(
        "http://google.com/abc/",
        result[0]
    );

    EXPECT_EQ(
        "https://openai.com/test/",
        result[1]
    );
}