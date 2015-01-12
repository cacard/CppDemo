//  TODO
//
//
//
//

#include <iostream>
using namespace std;

class MyClassForPlacementNew
{
private:
    int v = 1;
public:
    MyClassForPlacementNew()
    {
        cout << "ctor()" << endl;
    }

    ~MyClassForPlacementNew()
    {
        cout << "dtor()" << endl;
    }

    void PrintValue()
    {
        cout << "value:" << v << endl;
    }
};

void testPlacementNew()
{

}

int main()
{
    return 0;
}
