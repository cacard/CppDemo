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

    void HelloNoVirtual()
    {
        cout << "Hello from base,NoVirtual" << endl;
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

    virtual void Hello() override // C++11 可添加上此关键字
    {
        cout << "Hello from sub" << endl;
    }

    void HelloNoVirtual()
    {
        cout << "Hello from sub,NoVirtual" << endl;
    }
};


int main()
{
    Sub sub;
    ((Base)sub).HelloNoVirtual();

    return 0;
}
