#include "impl_pattern.h"
#include <iostream>

struct Foo::FooImpl
{
	~FooImpl()
	{
		using std::cout;
		using std::endl;
		cout << __FUNCTION__ << ": "<<x<<y<<z<<endl;
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
			,ImplSptr_( new FooImpl  )
{
	// 这里的本质区别是:
	// template<typename T , typename Deleter > unique_ptr<T> 的 Deleter 在模板具象化的时候生成
	// 而 获得具体代理类 T的 complete 型别 则是在 unique_ptr 构造函数获得(动态)
	// 这 2个时间点不一定是相同的
	// 典型的对于ImplPattern unique_ptr 使用者必须保证 Deleter 在 具体 unique_ptr 构造函数所在的代码内 出现实现
	// 否则 编译器对于 对于 delete incomplete type; 将生成 默认trivial destructor 如果 对象 本身有 non-trivial destructor
	// 那么就有 undefined behavior出现


	// shared_ptr 并没把 Deleter当做模板形参 , 他的实际"Deleter" 也是在 shared_ptr 构造函数 确定的，
	// 这2个( 编译器 获得对象具体型别 跟 生成对象的 delete 具体代码) 时间点是一致的
}

Foo::~Foo() = default;


void Foo::FooDo()
{
	ImplUptr_->x *= 100;
	ImplUptr_->y *= 100;
	ImplUptr_->z *= 100;

	ImplSptr_->x *= 10;
	ImplSptr_->y *= 10;
	ImplSptr_->z *= 10;
}

void Foo::FooBark()
{
	ImplUptr_->bark();
}
