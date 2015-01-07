#include <iostream>
#include <string>
#include <type_traits>

using std::cout;
using std::endl;

// is_integral 不会去除类型"引用",需要自己去除
template<typename T>
using IsIntegral = std::is_integral < typename std::remove_reference<T>::type > ;

template<typename T>
void logAndAddImpl(T&& t,std::false_type)
{
	cout << "false_type branch t: " << t << endl;
}

template<typename T>
void logAndAddImpl(T&& t,std::true_type)
{
	cout << "true_type branch t: " << t << endl;
}


template<typename T>
void logAndAdd(T&& t)
{
	logAndAddImpl(std::forward<T>(t),IsIntegral<T>());
}

/*
 * 
 */
class PersonV2
{
public:

	// pass by value
	explicit PersonV2( std::string str )
		: name_(std::move(str)){}
	explicit PersonV2( int idx ) 
		: name_(std::to_string(idx)){}

	PersonV2(const PersonV2& rhs) = default;

private:
	std::string name_;
};

class PersonV3
{
public:

	template
	<
		typename T,
		typename =	typename std::enable_if
					<
						!std::is_base_of<PersonV3 , typename std::decay<T>::type>::value
						&&
						!IsIntegral<T>::value
					>::type
	>
	explicit PersonV3(T&& t)
		: name_(std::forward<T>(t))
	{
		cout << "universal ctor:" << name_ << endl;
	}

	explicit PersonV3(int idx)
		: name_(std::to_string(idx))
	{
	}

	PersonV3(const PersonV3& rhs) = default;

private:
	std::string name_;
};



int main()
{
	logAndAdd(3);
	logAndAdd("3");

	PersonV2 p("James");
	auto cloneOfP(p); //< no error


	cout << std::is_same<PersonV3,const char[6]>::value << endl;
	PersonV3 p2("James"); // zzz..
	auto cloneOfP2(p2); //< no error
	
	PersonV3 p3(1234);
    return 0;
}
