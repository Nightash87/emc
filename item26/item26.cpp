#include <iostream>
#include <string>
#include <boost/lexical_cast.hpp>

using std::cout;
using std::endl;

/*
 * 
 */
class Person
{
public:

	// template universal ref ctor
	// greediest
	// dont do this!
	template<typename T>
	explicit Person(T&& t)
	: name_(std::forward<T>(t))
	{
		cout << "universal ctor:" << name_ << endl;
	}

	// cygwin ²»Ö§³Ö std::to_string ...
	explicit Person( int idx ) 
	: name_(boost::lexical_cast<std::string>(idx)){}

	Person(const Person& rhs) = default;
	
private:
	std::string name_;
};

int main()
{
	Person p("James");
	// auto cloneOfP(p); //< toggle compile error 
	auto cloneOfP(const_cast<const Person&>(p)); //< toggle ctor
    return 0;
}
