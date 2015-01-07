#include <iostream>
#include <string>
#include "../shared/widget.hpp"

using std::cout;
using std::endl;

/*
 * 
 */
using MyWidget = Widget < std::string > ;

// odd!
MyWidget Foo( MyWidget mw )
{
	mw.Bark();
	mw.SetT(std::string("Hello World"));
	return mw;
}

// correct
void FooV2( MyWidget&  mw)
{
	mw.Bark();
	mw.SetT(std::string("Hello World"));
}

int main()
{
	MyWidget mw;

	cout << "\n\nBeginFoo\n";
	auto s = Foo(mw);
	cout << "\n\nEndFoo\n";

	s.Report();
    return 0;
}
