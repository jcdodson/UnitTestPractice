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
TEST(PasswordTest, repeat_check_end)
{
	Password pass;
	ASSERT_EQ(1, pass.count_leading_characters("abbc"));

}
TEST(PasswordTest, multiple_repeats)
{
	Password pass;
	ASSERT_EQ(2, pass.count_leading_characters("aabaa"));
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
TEST(PasswordTest, leading_lower_with_trailing_lower)
{
        Password pass;
        ASSERT_EQ(true, pass.has_mixed_case("aaaaaaBaaaa"));
}
TEST(PasswordTest, mixed_with_space)
{
        Password pass;
        ASSERT_EQ(true, pass.has_mixed_case("a        B"));
}
TEST(PasswordTest, default_con_test){
	Password pass;
	ASSERT_EQ(true, pass.authenticate("ChicoCA-95929"));
}
TEST(PasswordTest, authenticate_test_basic){
	Password pass;
	pass.set("Cabinetdoor");
	ASSERT_EQ(true, pass.authenticate("Cabinetdoor"));
}
TEST(PasswordTest, auhenticate_test_oldpass){
	Password pass;
	pass.set("RandomPass");
	pass.set("ChicoCA-95929");
	ASSERT_EQ(false, pass.authenticate("ChicoCA-95929"));
}
TEST(PasswordTest, authenticate_sad_test){
	Password pass;
	pass.set("gggg y");
	ASSERT_EQ(false, pass.authenticate("gggg y"));
}
TEST(PasswordTest, authenticate_sad_test2){
	Password pass;
	pass.set("GGGGyyyy");
	ASSERT_EQ(false, pass.authenticate("GGGGyyyy"));
}
TEST(PasswordTest, authenticate_good_length){
	Password pass;
	pass.set("Poolside");
	ASSERT_EQ(true, pass.authenticate("Poolside"));
}
TEST(PasswordTest, authenticate_sad_length){
	Password pass;
	pass.set("Pool");
	ASSERT_EQ(false, pass.authenticate("Pool"));
}
TEST(PasswordTest, authenticate_leading_length){
        Password pass;
        pass.set("PPPoolside");
        ASSERT_EQ(true, pass.authenticate("PPPoolside"));
}
TEST(PasswordTest, authenticate_prev_pass){
	Password pass;
	pass.set("GoodPass");
	pass.set("ChicoCA-95929");
	pass.set("GoodPass");
	ASSERT_EQ(true, pass.authenticate("GoodPass"));
}
