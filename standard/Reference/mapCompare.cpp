#include <functional>
#include <iostream>
#include <set>

using namespace std;

class myClass {
public:
    int height, weight;
    class myGreaterCompareHeight {
        bool operator()(const myClass a, const myClass b)
        {
            return a.height > b.height;
        }
    };
    class myGreaterCompareWeight {
        bool operator()(const myClass a, const myClass b)
        {
            return a.weight > b.weight;
        }
    };
    myClass make_myClass(int h, int w);
    myClass(int h, int w);
    myClass();
};

myClass::myClass(int h, int w)
{
    height = h;
    weight = w;
}

myClass myClass::make_myClass(int h, int w)
{
    myClass tempMyClass(h, w);
    return tempMyClass;
}

set<myClass, myClass::myGreaterCompareHeight> sh;
set<myClass, myClass::myGreaterCompareWeight> sw;

int main()
{

    return 0;
}