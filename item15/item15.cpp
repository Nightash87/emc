#include <iostream>
#include <cmath>
#include <array>

using std::cout;
using std::endl;

/*
 * vs12 wont complile
 */ 

#ifndef WIN32



constexpr int pow(int base, int exp) noexcept
{
	return exp == 0 ? 1 : base * pow(base, exp - 1);
}
int main()
{
  const int i = 3;
  constexpr int a = i;
  std::array<int, pow(2, a)> arr = { 1, 2, 3, 4, 5, 6, 7, 8 };
  for ( auto& i : arr)
  {
	  cout << i << endl;
  }
  return 0;
}

#else // !WIN32

int main()
{
	cout << "vs12 dont support constexpr ..yet" << endl;
	return 0;
}

#endif
