#include <iostream>
#include <map>


using std::cout;
using std::endl;

/*
 * 
 */

class Foo 
{
public:
	Foo() { cout<<"Foo()"<<endl; }
	Foo( const Foo& ) {  cout<<"Foo(Foo& )"<<endl;  }  
};
int main()
{

  // ���﷢����4�ο������� 
  // 1 ������ʱ���� ������ ��ʼ���б�
  // 2 ��ʼ���б� ������ map

  std::map<int,Foo> im =  
  {
	  {1,Foo()},
	  {2,Foo()}
  };
  
  
  // �ǺǺǺ�..... i����ʱ����
  for( const std::pair<int,Foo>& i : im )
  {
	  cout<<i.first<<endl;
  }
  return 0;
}
