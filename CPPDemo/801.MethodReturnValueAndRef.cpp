/*
 *  函数返回对象值、对象引用测试
 *
 *  编译器的RVO行为。
 *
 */

#include <iostream>
#include <cstring>
using namespace std;


class Person
{
public:
    int age=1;

public:
    Person():age(1) // default ctor
    {
        cout << "-> ctor" << endl;
    }

    Person(int a)
        :age(a)
    {
        cout << "-> ctor" << endl;
    }

    Person(const Person& _p) // copy ctor
    {
        cout << "-> copy ctor" << endl;
        age = _p.age;
    }

    Person& operator =(const Person& _p) // copy-assignment operator
    {
        cout << "-> copy assignment operator" << endl;
        if(this==&_p)
        {
            return *this;
        }
        age=_p.age;
        return *this;
    }

    ~Person()
    {
        cout << "~Person" << endl;
    }
};

// #1 值传递，发生一次复制
void ParamUsingValue(Person p)
{
    cout << p.age << endl;
}

// #2 引用传递，不发生复制
void ParamUsingReference(Person& p)
{
    cout << p.age << endl;
}

// #3.1 函数返回局部对象（编译器优化，无临时变量拷贝）
//  * 编译器很可能发生RVO(返回值优化)，即把调用者的变量pReturn地址传递给该函数，函数内部的p在pReturn地址上创建
//  * GUN GCC debug 上的结果，对象(1)/(2)的地址相同，即函数返回对象时，未发生复制
Person ReturnLocalObject()
{
    Person p;
    p.age=2;
    cout << &p << endl;
    return p;
}

/*  #3.2 函数返回局部对象（编译器不能优化，发生临时变量拷贝）
 *
 */
 Person ReturnLocalObject2()
 {
     Person p1;
     Person p2;
     bool x;

     return x ? p1 : p2;
 }


//  #4 函数返回局部对象的引用
//   ！避免
//  * 在GUN GCC debug下，返回的对象析构后，后续代码依然可以访问。
Person& ReturnLocalReference()
{
    Person p;
    cout << &p << endl;
    return p;
}

//  #5 函数可返回非局部对象的引用
Person& ReturnNonLocalReference(Person& _p)
{
    return _p;
}

int main()
{
    Person p1;
    Person p2 = ReturnNonLocalReference(p1);
    cout << &p2 << "," << p2.age << endl;

    return 0;
}






