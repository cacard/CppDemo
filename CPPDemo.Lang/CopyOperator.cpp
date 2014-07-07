/*
 *   赋值操作符
 *
 *   属于复制控制
 *   默认情况下会生成一个，表示对对象的内存拷贝——即，值类型在Statck上复制（隐含的意思是，指针成员指向Heap中的同一个对象）。
 *
 */

#include <iostream>
using namespace std;

class Z
{
public:
    int a=0;

public:
    Z(){}

    Z&/*也可以是void，只是不支持a=b=c*/ operator =(const Z& _z)
    {
        cout << "-> operator = ()" << endl;
        if(this==&_z) // 如果是自身，立即返回
        {
            cout << "copy your self" << endl;
            return *this;
        }

        this->a=_z.a+1; //复制时，a++
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


int main20()
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
    cout << z.a << "," << zz.a << endl; // 1,2

    return 0;
}
