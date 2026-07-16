// #include <gtest/gtest.h>
// #include "../include/Set.h"

// class SetTest : public ::testing::Test
// {
// protected:
//     Set<int> s;
// };

// TEST_F(SetTest, EmptySet)
// {
//     EXPECT_EQ(0, s.size());
// }

// TEST_F(SetTest, InsertOneElement)
// {
//     s.insert(10);

//     EXPECT_TRUE(s.exists(10));
//     EXPECT_EQ(1, s.size());
// }

// TEST_F(SetTest, InsertMultipleElements)
// {
//     s.insert(10);
//     s.insert(20);
//     s.insert(30);

//     EXPECT_TRUE(s.exists(10));
//     EXPECT_TRUE(s.exists(20));
//     EXPECT_TRUE(s.exists(30));

//     EXPECT_EQ(3, s.size());
// }

// TEST_F(SetTest, DuplicateInsertion)
// {
//     s.insert(10);
//     s.insert(10);
//     s.insert(10);

//     EXPECT_EQ(1, s.size());
//     EXPECT_TRUE(s.exists(10));
// }

// TEST_F(SetTest, RemoveElement)
// {
//     s.insert(10);
//     s.insert(20);

//     s.remove(10);

//     EXPECT_FALSE(s.exists(10));
//     EXPECT_TRUE(s.exists(20));
//     EXPECT_EQ(1, s.size());
// }

// TEST_F(SetTest, RemoveNonExistingElement)
// {
//     s.insert(10);

//     s.remove(50);

//     EXPECT_TRUE(s.exists(10));
//     EXPECT_EQ(1, s.size());
// }

// TEST_F(SetTest, ExistsForMissingElement)
// {
//     EXPECT_FALSE(s.exists(100));
// }

// TEST_F(SetTest, GetAllElements)
// {
//     s.insert(5);
//     s.insert(10);
//     s.insert(15);

//     DynamicArray<int> values = s.getAll();

//     EXPECT_EQ(3, values.size());

//     EXPECT_TRUE(
//         values.exists(5)
//     );

//     EXPECT_TRUE(
//         values.exists(10)
//     );

//     EXPECT_TRUE(
//         values.exists(15)
//     );
// }

// TEST_F(SetTest, ClearSet)
// {
//     s.insert(1);
//     s.insert(2);
//     s.insert(3);

//     s.clear();

//     EXPECT_EQ(0, s.size());
//     EXPECT_FALSE(s.exists(1));
//     EXPECT_FALSE(s.exists(2));
//     EXPECT_FALSE(s.exists(3));
// }

// TEST_F(SetTest, StringSet)
// {
//     Set<std::string> names;

//     names.insert("Alice");
//     names.insert("Bob");

//     EXPECT_TRUE(names.exists("Alice"));
//     EXPECT_TRUE(names.exists("Bob"));

//     names.remove("Alice");

//     EXPECT_FALSE(names.exists("Alice"));
//     EXPECT_TRUE(names.exists("Bob"));
// }