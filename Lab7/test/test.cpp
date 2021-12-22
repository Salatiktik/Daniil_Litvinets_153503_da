#include "pch.h"

TEST(Case1, Test1) {
    char* n = new char[8]{ '6','6','6',',','6','6','6' };

    EXPECT_EQ(main1(n, 0, 3, 7), "246.BB6B6");
}

TEST(Case2, Test1) {
    char* n = new char[3]{ '6','6','6' };

    EXPECT_EQ(main1(n, 0, 3, 3), "246");
}

TEST(Case3, Test1) {
    char* n = new char[1]{ '0' };

    EXPECT_EQ(main1(n, 0, 1, 1), "0");
}

TEST(Case4, Test1) {
    char* n = new char[8]{ '1','2','3',',','1','2','3'};

    EXPECT_EQ(main1(n, 0, 3,7), "56.23860");
}

TEST(Case1, Test2) {
    string n = "01101010,100101";
    EXPECT_EQ(main2(n, 0, 8, 15), "01101010,100101");
}

TEST(Case2, Test2) {
    string n = "01101010";
    EXPECT_EQ(main2(n, 0, 8, 8), "01101010");
}

TEST(Case3, Test2) {
    string n = "11101010";
    EXPECT_EQ(main2(n, 0, 8, 8), "00010101");
}

TEST(Case4, Test2) {
    string n = "11101010,001001";
    EXPECT_EQ(main2(n, 0, 8, 15), "00010101,110110");
}

TEST(Case1, Test3) {
    string num1 = "0100101,1101001";
    string num2 = "0100100,1";
    EXPECT_EQ(main3(num1, num2, 16, 10, 7, 7, 0, 0),"10001010,0101001");
}

TEST(Case2, Test3) {
    string num1 = "1100101,1101001";
    string num2 = "0100100,1";
    EXPECT_EQ(main3(num1, num2, 16, 10, 7, 7, 0, 0), "11111110,1010111");
}

TEST(Case1, Test4) {
    string num1 = "264517AB";
    string num2 = "4726184A";
    EXPECT_EQ(main4(num1, num2, '+', '+', 8, 8), "+716B3439");
}

TEST(Case2, Test4) {
    string num1 = "123264517AB";
    string num2 = "4726184A";
    EXPECT_EQ(main4(num1, num2, '-', '+', 11, 8), "-1229B1ABB61");
}

TEST(Case3, Test4) {
    string num1 = "123264517AB";
    string num2 = "4726184A";
    EXPECT_EQ(main4(num1, num2, '+', '-', 11, 8), "+1229B1ABB61");
}

TEST(Case4, Test4) {
    string num1 = "4787BA676";
    string num2 = "4726184A";
    EXPECT_EQ(main4(num1, num2, '-', '-', 9, 8), "-503A60304");
}

TEST(Case1, Test5) {
    int N = 1;
    EXPECT_EQ(main5(N), "I");
}

TEST(Case2, Test5) {
    int N = 10;
    EXPECT_EQ(main5(N), "X");
}

TEST(Case3, Test5) {
    int N = 100;
    EXPECT_EQ(main5(N), "C");
}

TEST(Case4, Test5) {
    int N = 3999;
    EXPECT_EQ(main5(N), "MMMCMXCIX");
}

TEST(Case5, Test5) {
    int N = 999;
    EXPECT_EQ(main5(N), "CMXCIX");
}

TEST(Case1, Test6)
{
    int N = 9;
    EXPECT_EQ(int(N + 1) / 10, 1);
}

TEST(Case2, Test6)
{
    int N = 90;
    EXPECT_EQ(int(N + 1) / 10, 9);
}

TEST(Case3, Test6)
{
    int N = 345678;
    EXPECT_EQ(int(N + 1) / 10, 34567);
}

TEST(Case4, Test6)
{
    int N = 3458;
    EXPECT_EQ(int(N + 1) / 10, 345);
}

TEST(Case1, Test7)
{
    int n = 37 * 3;
    EXPECT_EQ(main7(n), "++-");
}

TEST(Case2, Test7)
{
    int n = 37 * 3*89;
    EXPECT_EQ(main7(n), "+++");
}

TEST(Case3, Test7)
{
    int n = 3 * 89;
    EXPECT_EQ(main7(n), "+-+");
}


TEST(Case4, Test7)
{
    int n = 1;
    EXPECT_EQ(main7(n), "---");
}

TEST(Case1, Test8)
{
    unsigned long long n = 11;
    EXPECT_EQ(main8(n), "1101");
}

TEST(Case2, Test8)
{
    unsigned long long n = 10;
    EXPECT_EQ(main8(n),"1100");
}

TEST(Case3, Test8)
{
    unsigned long long n = 100;
    EXPECT_EQ(main8(n), "11000000");
}


TEST(Case1, Test9)
{
    int n = 345;
    EXPECT_EQ(main9(n), "33133");
}

TEST(Case2, Test9)
{
    int n = 32738;
    EXPECT_EQ(main9(n), "1122213112");
}

TEST(Case3, Test9)
{
    int n = 3;
    EXPECT_EQ(main9(n), "3");
}

TEST(Case4, Test9)
{
    int n = 12343;
    EXPECT_EQ(main9(n), "121213311");
}

TEST(Case5, Test9)
{
    int n = 12;
    EXPECT_EQ(main9(n), "33");
}