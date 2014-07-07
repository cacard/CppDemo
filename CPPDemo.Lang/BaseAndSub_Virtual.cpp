/*
 *   Virtual Method
 *
 */

#include <iostream>
using namespace std;

class Base
{
private:
    int age;
    char * name;

public:
    Base()
    {
        cout << "Base's ctor()" << endl;
    }

    ~Base()
    {
        cout << "Base's ~" << endl;
    }

    virtual void Hello()
    {
        cout << "Hello from base" << endl;
    }
};

class Sub : public Base
{
public:
    Sub()
    {
        cout << "Sub's ctor" << endl;
    }

    ~Sub()
    {
        cout << "Sub's ~" << endl;
    }

    virtual void Hello()
    {
        cout << "Hello from sub" << endl;
    }
};


int main_3()
{
    Base * base = new Sub();
    base->Base::Hello();

    cout << "--------" << endl;

    Base base2;
    Sub sub2; // 先调用 base's ctor，再调用自己的ctor

    base2=sub2;
    base2.Hello();

    return 0;
}
