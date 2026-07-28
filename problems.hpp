#pragma once
#include <string>

namespace myNamespace
{
int pow( int, int );
int atoi( const std::string& );

int atoi( const std::string& number )
{
  auto i{ 0u };
  for ( const auto& c : number )
  {
    if ( c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z' || c == ' ' )
      return 0;

    if ( i != 0u && c == '-' || c == '+' )
    {
      return 0;
    }

    ++i;
  }

  const size_t minPos = number.find( '-' );
  const size_t plsPos = number.find( '+' );

  if ( minPos != std::string::npos && minPos != 0 )
    return 0;

  if ( plsPos != std::string::npos && plsPos != 0 )
    return 0;

  using namespace std;

  uint32_t flags{ 0u };

  constexpr int skip = 1 << 0;
  constexpr int flip = 1 << 1;
  if ( number[0] == '-' )
  {
    // pos 0 is skip
    // pos 1 is flip
    flags ^= skip;
    flags ^= flip;
  }

  int it{ 0 };
  int res{ 0 };

  // even with my pow it is faster than std::pow
  // size_t i_{ number.size() - 2 };
  for ( ; it < number.size(); ++it )
  {
    if ( flags & ( skip ) )
    {
      ++it;
      // clear the skip
      flags &= ~( skip );
    }
    // -3214
    // 3
    // 30 + 2
    // 320 + 1
    // 3210 + 4
    // 3214
    // -3214
    res = res * 10 + ( number[it] - '0' );
    // res += ( number[it] - '0' ) * pow( 10, i_ );
  }

  return flags & ( flip ) ? res * -1 : res;
}

int pow( int a, int b )
{
  int result = 1;

  while ( b > 0 )
  {
    result *= a;
    --b;
  }

  return result;
}
} // namespace myNamespace
