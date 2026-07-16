#include <gtest/gtest.h>
#include "../include/Queue.h"

class QueueTest : public ::testing::Test
{
protected:
    Queue<int> q;
};

TEST_F(QueueTest, EmptyQueue)
{
    EXPECT_TRUE(q.empty());
    EXPECT_EQ(0, q.size());
}

TEST_F(QueueTest, PushOneElement)
{
    q.push(10);

    EXPECT_FALSE(q.empty());
    EXPECT_EQ(1, q.size());
    EXPECT_EQ(10, q.front());
}

TEST_F(QueueTest, PushMultipleElements)
{
    q.push(10);
    q.push(20);
    q.push(30);

    EXPECT_EQ(3, q.size());
    EXPECT_EQ(10, q.front());
}

TEST_F(QueueTest, PopSingleElement)
{
    q.push(100);

    EXPECT_EQ(100, q.pop());

    EXPECT_TRUE(q.empty());
    EXPECT_EQ(0, q.size());
}

TEST_F(QueueTest, PopMaintainsFIFO)
{
    q.push(10);
    q.push(20);
    q.push(30);

    EXPECT_EQ(10, q.pop());
    EXPECT_EQ(20, q.pop());
    EXPECT_EQ(30, q.pop());

    EXPECT_TRUE(q.empty());
}

TEST_F(QueueTest, FrontAfterPop)
{
    q.push(1);
    q.push(2);
    q.push(3);

    q.pop();

    EXPECT_EQ(2, q.front());
}

TEST_F(QueueTest, SizeAfterPushAndPop)
{
    q.push(1);
    q.push(2);
    q.push(3);

    EXPECT_EQ(3, q.size());

    q.pop();

    EXPECT_EQ(2, q.size());

    q.pop();

    EXPECT_EQ(1, q.size());
}

TEST_F(QueueTest, PushAfterEmpty)
{
    q.push(5);

    q.pop();

    q.push(100);

    EXPECT_EQ(100, q.front());
    EXPECT_EQ(1, q.size());
}

TEST_F(QueueTest, StringQueue)
{
    Queue<std::string> s;

    s.push("Hello");
    s.push("World");

    EXPECT_EQ("Hello", s.front());

    EXPECT_EQ("Hello", s.pop());

    EXPECT_EQ("World", s.front());
}

TEST_F(QueueTest, LargeNumberOfElements)
{
    for(int i=0;i<1000;i++)
        q.push(i);

    EXPECT_EQ(1000,q.size());

    for(int i=0;i<1000;i++)
        EXPECT_EQ(i,q.pop());

    EXPECT_TRUE(q.empty());
}