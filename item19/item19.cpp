#include <iostream>
#include <memory>
#include <boost/shared_ptr.hpp>
#include <string>
#include "../shared/widget.hpp"

using std::cout;
using std::endl;

/*
 *
 */

using MyWidget = Widget<std::string>;
using MyWidgetSptr = std::shared_ptr<MyWidget>;
using MyWidgetBoostSptr = boost::shared_ptr<MyWidget>;

int main()
{
    cout << "note:using anonymity lambda deleter init shared_ptr...\n";

    auto spW1 = MyWidgetSptr(new MyWidget { "Hello World" },
                             [](MyWidget * pW)
    {
        cout << "Bark On Delete %%version1%%:\t";
        pW->Bark();
        delete pW;
    });

    auto spW2 = MyWidgetSptr(new MyWidget { "GoodBye World" },
                             [](MyWidget * pW)
    {
        cout << "Bark On Delete $$version2$$:\t";
        pW->Bark();
        delete pW;
    });

	// "same control block"
    auto spW2_clone = spW2;


    cout << "spW1.swap(spW2)\n";
    spW1.swap(spW2);
    spW1 = nullptr;
    spW2 = nullptr;

	cout << "reset spW2_clone\n";
	spW2_clone = nullptr;
    return 0;
}
