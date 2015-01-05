#include "impl_pattern.h"
#include <iostream>

struct Foo::FooImpl
{
	~FooImpl()
	{
		using std::cout;
		using std::endl;
		cout << __FUNCTION__ << endl;
	}
	int x = 2;
	int y = 3;
	int z = 4;

	void bark()
	{
		using std::cout;
		using std::endl;

		cout << "x:" << x << '\t';
		cout << "y:" << y << '\t';
		cout << "z:" << z << '\t';
	}
};



Foo::Foo():ImplUptr_( new FooImpl , FooImplDeleter() ) 
			// ,ImplUptr2_( new FooImpl )
{

}

Foo::~Foo() = default


void Foo::FooDo()
{
	ImplUptr_->x *= 100;
	ImplUptr_->y *= 100;
	ImplUptr_->z *= 100;
}

void Foo::FooBark()
{
	ImplUptr_->bark();
}
