#include <iostream>
#include <string>

using std::cout;
using std::endl;

/*
 *
 */

class Widget
{
public:
	Widget()
	{
		cout << __FUNCTION__ << endl;
	}
    Widget(int i, double d )
    {
        cout << __FUNCTION__ << " int i, double d" << endl;
    }

    Widget(int i, std::string)
    {
        cout << __FUNCTION__ << " int i, bool d" <<endl;
    }

	// ill form
	Widget(std::initializer_list<double> dl , bool b = true)
	{
		cout << __FUNCTION__ << " initializer_list" << " b:" << b << endl;
		cout << "abc";
	}
};

int main()
{
	// "strongly" prefer pick initializer_list version first if it exists , even through parameter conversion
	Widget w{ 3, 5.0 };

	// warning here , treated as function declaration ..."vexing parse"
	Widget w2(); 

	// call default ctor , not empty initializer_list
	Widget w_default{};

	// call eh... ???
	Widget w_empty_list{ {} };
    return 0;
}
