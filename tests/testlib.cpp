
#include "Maths/Vector.h"
#include "gtest/gtest.h"

TEST(MathsVector, hello)
{
  peds::Vector myVec;
  myVec.Hello();
  EXPECT_EQ(1000, 1000);
}

int main(int argc, char** argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
