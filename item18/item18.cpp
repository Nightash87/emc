#include <iostream>
#include <memory>
#include <boost/smart_ptr.hpp>

using std::cout;
using std::endl;

/*
 *
 */

class Widget
{
public:
    explicit Widget(int i) : data_(i) {}
    void Foo()
    {
        cout << __FUNCTION__ << "  :" <<data_ << endl;
    }
private:
    int data_;
};

auto WidgeDeleter = [](Widget * pWidge)
{
	if ( pWidge )
	{
		pWidge->Foo();
	}
	else
	{
		cout << "nullptr case" << "..." << endl;
	}
    
    delete pWidge;
};

using WidgetUptr = std::unique_ptr < Widget , decltype(WidgeDeleter)> ;
using WidgetSptr = std::shared_ptr < Widget >;
using WidgetBoostSptr = boost::shared_ptr < Widget > ;

int main()
{
    {
		cout << "Case 1: uptr with null case" << endl;
		// wont toggle nullptr case
        WidgetUptr uptr(nullptr, WidgeDeleter);
        uptr.reset(new Widget(3));

		// move to shared_ptr
		cout << "uptr move to shared_ptr" << endl;
		WidgetSptr sptemp = std::move(uptr);
    }

	{
		cout << "\n\nCase 2: std::shared_ptr with null case" << endl;
		// toggle nullptr case
		WidgetSptr sptr(nullptr, WidgeDeleter);
		sptr.reset(new Widget(300), WidgeDeleter);
	}
	
	{
		cout << "\n\nCase 3" << endl;
		// toggle nullptr case
		WidgetBoostSptr boostSptr(nullptr, WidgeDeleter);
		cout << "use_count of boostSptr(nullptr):" << boostSptr.use_count() << endl;
		boostSptr.reset(new Widget(300), WidgeDeleter);
		
		cout << "assign nullptr explictly again.." << endl;
		boostSptr = nullptr;
		cout << "which runtime deleter is:" << boostSptr._internal_get_untyped_deleter() << endl;
		cout << "use_count of nullptr" << "boostSptr.use_count()" << endl;
	}
    return 0;
}
