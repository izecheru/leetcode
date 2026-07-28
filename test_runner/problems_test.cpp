#include "../problems.hpp"
#include <gtest/gtest.h>

namespace tests
{
TEST( LeetCodeTests, AtoiTest )
{
  EXPECT_EQ( myNamespace::atoi( "-123" ), -123 );
  EXPECT_EQ( myNamespace::atoi( "a-123" ), 0 );
  EXPECT_EQ( myNamespace::atoi( "-1-23" ), 0 );
  EXPECT_EQ( myNamespace::atoi( "-123+" ), 0 );
  EXPECT_EQ( myNamespace::atoi( "+123+" ), 0 );
}

TEST( LeetCodeTests, PowTest )
{
  EXPECT_EQ( myNamespace::pow( 10, 2 ), 100 );
  EXPECT_EQ( myNamespace::pow( 0, 2 ), 0 );
  EXPECT_EQ( myNamespace::pow( 1, 2 ), 1 );
  EXPECT_EQ( myNamespace::pow( 4, 2 ), 16 );
  EXPECT_EQ( myNamespace::pow( 125, 3 ), 1953125 );
}
} // namespace tests