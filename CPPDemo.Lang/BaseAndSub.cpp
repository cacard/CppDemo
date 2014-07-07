/*
*   ผฬณะ
*
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

    void Hello()
    {
        cout << "Hello." << endl;
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

    void Hello()
    {
        cout << "Hello from sub" << endl;
    }
};


int main_2()
{
    Sub sub;
    sub.Hello();
    return 0;
}
