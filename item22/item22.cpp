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
		// !!Ç±ÔÚÄÚ´æĞ¹Â¶
		Foo f;
		f.FooDo();
		f.FooBark();
	}
    return 0;
}
