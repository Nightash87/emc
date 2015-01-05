#pragma once

#include <memory>

class Foo
{
public:
	Foo();
	~Foo();
	void FooDo();
	void FooBark();
private:
	struct FooImpl;

	// 因为FooImplDeleter 在.h中 这时候  FooImpl 还是imcomplete type 所以delete 是无效的(不会触发FooImpl 析构函数)
	// 潜在内存泄露
	// 解决方法:需要把 FooImplDeleter 移入 .cpp中
	struct FooImplDeleter
	{
		void operator()( FooImpl* p )
		{
			delete p;
		}
	};
	
	using ImplUptr = std::unique_ptr < FooImpl , FooImplDeleter > ;
	using ImplSptr = std::shared_ptr < FooImpl > ;
private:
	ImplUptr ImplUptr_;
	ImplSptr ImplSptr_;
};