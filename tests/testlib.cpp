
#include "gtest/gtest.h"
#include "Maths/Vector.h"

TEST(MathsVector, hello)
{
  peds::Vector myVec;
  myVec.hello();
  EXPECT_EQ(1000, 1000);	
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
