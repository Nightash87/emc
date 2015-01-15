#include <iostream>
#include <string>
#include <functional>
#include <boost/bind.hpp>

#include "../shared/widget.hpp"

using std::cout;
using std::endl;

/*
 * std::bind move and lambda
 */

using MyWidget = Widget<std::string>;

int main()
{
	cout<<"---- std::bind move and lambda ---"<<endl;
	MyWidget w;
	w.SetT("Hello Item32");
	auto func = std::bind([](MyWidget& w) mutable -> bool   { w.SetT("Item32 Hello"); w.Bark(); return true; }
						  , std::move(w));
	cout<<func()<<endl;
    return 0;
}

/* c++14 perfect forwarding lambda
   auto f  = 
		[](auto&&... params)
		{
			return func(std::forward<decltype(params)>(params)...);
		}
 */