#include <iostream>
#include <string>

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

	explicit Person( int idx ) 
	: name_(std::to_string(idx)){}

	Person(const Person& rhs) = default;
	// Person(Person&& rhs) = default;

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
