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

	// ��ΪFooImplDeleter ��.h�� ��ʱ��  FooImpl ����imcomplete type ����delete ����Ч��(���ᴥ��FooImpl ��������)
	// Ǳ���ڴ�й¶
	// �������:��Ҫ�� FooImplDeleter ���� .cpp��
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