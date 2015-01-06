#include <iostream>
#include <string>
#include "../shared/widget.hpp"

using std::cout;
using std::endl;

/*
 * 
 */
using MyWidget = Widget < std::string > ;

MyWidget Foo( MyWidget mw )
{
	mw.Bark();
	mw.SetT(std::string("Hello World"));
	return mw;
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
