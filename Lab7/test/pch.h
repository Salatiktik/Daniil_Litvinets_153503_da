//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <cmath>
#include <string>

using namespace std;

string main1(char* mass, int zn, int dot, int len);

string main2(string mass, int zn, int dot, int len);

void obr(string& str, int i);
void dop(string& str, int i);
void sum(string& str1, string& str2, int len1, int len2, int dot1, int dot2);
string main3(string num1, string num2, int len1, int len2, int dot1, int dot2, int zn1, int zn2);

int biggest(string str1, string str2, int len);
int find_sym(char a, string str, int len);
void remove_one(string& str, int t, string str_tw);
int add_one(string& str, int t, string str_tw, int& len);
void sum(string& str1, string& str2, int len1, int len2, string& str_tw);
void vich(string& str1, string& str2, int len1, int len2, string& str_tw);
string main4(string num1, string num2, char zn1, char zn2, int len1, int len2);

string main5(int N);

string main7(int n);

string main8(int n);

string main9(int n);