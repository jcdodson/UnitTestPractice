/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
    Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1,actual);
}
TEST(PasswordTest, double_letter_password)
{
    Password my_password;
        int actual = my_password.count_leading_characters("xx");
        ASSERT_EQ(2,actual);
}
TEST(PasswordTest, triple_letter_password)
{
    Password my_password;
        int actual = my_password.count_leading_characters("yyy");
        ASSERT_EQ(3,actual);
}
TEST(PasswordTest, quad_letter_password)
{
    Password my_password;
        int actual = my_password.count_leading_characters("ffff");
        ASSERT_EQ(4,actual);
}
TEST(PasswordTest, quin_letter_password)
{
    Password my_password;
        int actual = my_password.count_leading_characters("AAAAA");
        ASSERT_EQ(5,actual);
}
TEST(PasswordTest, SEX_letter_password)
{
    Password my_password;
        int actual = my_password.count_leading_characters("XXXXXX");
        ASSERT_EQ(6,actual);
}
TEST(PasswordTest, repeat_check_end)
{
	Password pass;
	ASSERT_EQ(1, pass.count_leading_characters("abbc"));

}
TEST(PasswordTest, multiple_repeats)
{
	Password pass;
	ASSERT_EQ(1, pass.count_leading_characters("abaa"));
}
TEST(PasswordTest, empty_pass)
{
	Password pass;
	ASSERT_EQ(1, pass.count_leading_characters(""));
}
TEST(PasswordTest, mixed_2_letter)
{
	Password pass;
	ASSERT_EQ(true, pass.has_mixed_case("Ab"));
}
TEST(PasswordTest, lower_2_letter)
{
        Password pass;
        ASSERT_EQ(false, pass.has_mixed_case("aa"));
}
TEST(PasswordTest, upper_2_letter)
{
        Password pass;
        ASSERT_EQ(false, pass.has_mixed_case("BB"));
}
TEST(PasswordTest, empty_mix)
{
        Password pass;
        ASSERT_EQ(false, pass.has_mixed_case(""));
}
