#include <iostream>
#include <string>
#include <vector>
#include <cassert>
#include <boost/type_index.hpp>
#include <type_traits>

using std::cout;
using std::endl;
using boost::typeindex::type_id_with_cvr;

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
	cout << "decltype(c[i])	" << type_id_with_cvr<decltype(c[i])>().pretty_name() << '\n';
	return c[i];
}

int main(void)
{
	auto v = GetValue( std::vector<int>{1,2,3,4,5} , 4 );
	v = 50;
	cout << "v:	" << type_id_with_cvr<decltype(v)>().pretty_name() << '\n';

	std::vector<int> ivec = { 1,2,3,4,5};
	auto& refV = GetValueByRef(ivec,4);
	refV = 500;
	cout << "refV:	" << type_id_with_cvr<decltype(refV)>().pretty_name() << '\n';
	cout<<" size of int:"<<sizeof(int)<<'\n';
	cout<<"size of int  * __ptr64"<<sizeof(int  * __ptr64)<<endl;
	cout<<std::is_same<int, int  * __ptr64>::value<<endl;
	return 0;
}


