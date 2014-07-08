/*
 *   赋值操作符 copy assignment operator
 *
 *   属于复制控制
 *   默认情况下会生成一个，浅克隆。
 *
 */

#include <iostream>
using namespace std;

class Z
{
public:
    int a=0;

public:
    Z():a(1)
    {
        cout << "->ctor default" << endl;
    }

    Z& operator =(const Z& _z)
    {
        cout << "-> operator = ()" << endl;

        if(this==&_z) // 如果是自身，立即返回
        {
            cout << "copy your self" << endl;
            return *this;
        }

        this->a=_z.a;
        return *this;
    }

    Z(const Z& _z)
    {
        cout << "-> copy ctor" << endl;
        this->a=_z.a;
    }

    ~Z()
    {
        cout << "~Z()" << endl;
    }
};


int main32()
{
    Z z;
    Z zz;
    zz = z;

    /* 这种写法是通过拷贝构造函数进行复制的，而不是通过赋值操作符。*/
    /*
    Z z;
    Z zz = z; // 等价于 Z zz(z);
    */

    cout << &z << "," << & zz << endl; // 0x28fefc,0x28fef8
    cout << z.a << "," << zz.a << endl;

    return 0;
}
