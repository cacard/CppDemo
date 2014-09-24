/*
 *   Virtual:虚函数与多态
 *
 *      虚函数，表示基类希望子类覆盖实现该函数
 *      子类的普通方法也可以对父类的同名方法进行覆盖，但无多态

 *      早绑定/晚绑定
 *          - 编译期可确定具体的函数调用，称为早绑定（编译期绑定），比如函数重载。其实，函数重载也是多态的一种形式，只是不是我们常说的那种真正多态。
 *          - 运行期才能确定的函数调用，称为晚绑定（运行期绑定），比如virtual方法的覆盖。
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

    // 普通方法对父类进行了覆盖或者重写，但不实现多态
    void HelloNoVirtual()
    {
        cout << "Hello from sub,NoVirtual" << endl;
    }
};


int main()
{
    Sub sub;
    //sub.Hello();

    Base b=(Base)sub;
    b.Hello();
    //((Base)sub).Hello();
    //((Base)sub).HelloNoVirtual();

    return 0;
}
