#include <iostream>
#include <memory>
#include "impl_pattern.h"

using std::cout;
using std::endl;

/*
 * 
 */


int main()
{

	{
		// !!Ǳ���ڴ�й¶
		Foo f;
		f.FooDo();
		f.FooBark();
	}
    return 0;
}
