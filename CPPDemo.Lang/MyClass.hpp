#ifndef MYCLASS1_HPP_INCLUDED
#define MYCLASS1_HPP_INCLUDED
#endif // MYCLASS1_HPP_INCLUDED

/*
 *  测试用的通用类
 */

#include <iostream>
using namespace std;

class MyClass
{
    string str;
    int* data;

public:
    MyClass()
    {
        cout << "ctor default" << endl;
    }

    MyClass(string _str)
    {
        cout << "ctor(string)" << endl;
        str=_str;
    }

    ~MyClass()
    {
        cout << "~MyClass() ,str=" << str << endl;
    };

    void Print()
    {
        cout << str << endl;
    }
};


