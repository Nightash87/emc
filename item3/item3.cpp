#include <iostream>
#include <string>
#include <vector>
#include <cassert>

using std::cout;
using std::endl;

template<typename Container, typename Index >
auto
GetValue(Container&& c, Index i)
-> decltype(std::forward<Container>(c)[i])
{
	return std::forward<Container>(c)[i];
}

template<typename Container, typename Index >
auto
GetValueByRef(Container& c, Index i)
-> decltype(c[i])
{
	return c[i];
}

int main(void)
{
	
	auto v = GetValue( std::vector<int>{1,2,3,4,5} , 4 );
	cout<< GetName( typeid(v).name() );
	v = 50;


	std::vector<int> ivec = { 1,2,3,4,5};
	int& refV = GetValueByRef(ivec,4);
	refV = 500;
	cout<< GetName( typeid(refV).name() );
	return 0;
}


