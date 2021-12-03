#include "pch.h"

TEST(Case1, Test9) {
	string s = "sdfghjkgfdfghjkhgfdfghjkhgfdfghjklkjgfdcx1dfghjkgfghjkgfdfghjkfdf1fghjkgfghjkfdfghjklfd1fghjkl";
  EXPECT_EQ(main1(s), 3);
}

TEST(Case2, Test9) {
	string s = "100fghjkljhg2e2dfghjk300,500dfghjk400500e-3dfghj";
	EXPECT_EQ(main1(s), 1001);
}