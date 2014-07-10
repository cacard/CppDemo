/*
 *   拷贝赋值操作符： copy assignment operator
 *
 *  注1：赋值操作符并不是“构造函数”
 *  注2：名称中的“copy”意味着与拷贝相关，在函数内部实现拷贝。
 *
 *  why?

 *  how?
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

    // 赋值运算符重载
    //  如果参数是(const Z _z)会发生什么？
    //      会在调用该函数时发生一次没有必要的对象拷贝（即调用了 copy ctor）。
    //  如果返回值是Z而不是Z&会发生什么？
    //      会发生一次对象拷贝。
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


int main()
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
