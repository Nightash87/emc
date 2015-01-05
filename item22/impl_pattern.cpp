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
	// ����ı���������:
	// template<typename T , typename Deleter > unique_ptr<T> �� Deleter ��ģ����󻯵�ʱ������
	// �� ��þ�������� T�� complete �ͱ� ������ unique_ptr ���캯�����(��̬)
	// �� 2��ʱ��㲻һ������ͬ��
	// ���͵Ķ���ImplPattern unique_ptr ʹ���߱��뱣֤ Deleter �� ���� unique_ptr ���캯�����ڵĴ����� ����ʵ��
	// ���� ���������� ���� delete incomplete type; ������ Ĭ��trivial destructor ��� ���� ������ non-trivial destructor
	// ��ô���� undefined behavior����


	// shared_ptr ��û�� Deleter����ģ���β� , ����ʵ��"Deleter" Ҳ���� shared_ptr ���캯�� ȷ���ģ�
	// ��2��( ������ ��ö�������ͱ� �� ���ɶ���� delete �������) ʱ�����һ�µ�
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
