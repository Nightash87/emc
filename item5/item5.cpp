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

  // 这里发生了4次拷贝调用 
  // 1 先是临时变量 拷贝到 初始化列表
  // 2 初始化列表 拷贝到 map

  std::map<int,Foo> im =  
  {
	  {1,Foo()},
	  {2,Foo()}
  };
  
  
  // 呵呵呵呵..... i是临时变量
  for( const std::pair<int,Foo>& i : im )
  {
	  cout<<i.first<<endl;
  }
  return 0;
}
