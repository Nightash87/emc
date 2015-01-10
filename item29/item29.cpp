#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <boost/lexical_cast.hpp>
#include "../shared/widget.hpp"

using std::cout;
using std::endl;

/*
 * iota_x
 */

template<class ForwardIterator , class NumberType , class Transformer >
void iota_x(ForwardIterator iterBegin, ForwardIterator iterEnd, NumberType seed, const Transformer& trans)
{
    auto iter = iterBegin;

    while (iter != iterEnd)
    {
        // RVO rvalue optimized
        *(iter++) = trans(seed++);
    }
}

using MyWidget = Widget < std::string > ;
using MyWidgetArr = std::array < MyWidget, 10 > ;

int main()
{
    MyWidgetArr mwa1;
    iota_x(mwa1.begin(),
           mwa1.end(),
           0,
           [](int seed) -> MyWidget
    {
        return MyWidget(boost::lexical_cast<std::string>(seed));
    });

    // msvc wont trigger move operator because its array<T> dont have move syntax AT ALL
    // gcc will do fine( test env version of gcc :4.8.3 )
    cout << "\n--moving array" << endl;
    auto mwa2 = std::move(mwa1);

    for ( const auto& i : mwa2 )
    {
        i.Report();
        cout << "----\n";
    }

    return 0;
}
