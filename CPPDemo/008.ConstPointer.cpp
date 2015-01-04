//
//  const pointer
//
//  C++ Primer中两个概念：top-level const（修饰指针）和low-level const（修饰指针指向的对象）。
//  可按编译器一般采用LR(k)这个理念分析，即修饰符均是修饰右边。

#include <iostream>
using namespace std;

void t1()
{
    const int a = 1;
}

void t2()
{
    int a = 1;
    int b = 2;
    const int* p = &a; // const 修饰*p，即修饰指针指向的对象
    //*p = b; // error
    p = &b;

    cout << *p << endl;
}

void t3()
{
    int a = 1;
    int b = 2;
    int const * p = &a; // const修饰*p
    //*p = b;
    p = &b;

    cout << *p << endl;
}

void t4()
{
    int a = 1;
    int b = 2;
    int* const p = &a; // const修饰p，即修饰指针
    *p = b;
    cout << *p << endl;

    //p = &b;
}

void t5()
{
    int a = 1;
    int b = 2;
    const int * const p = &a; // 指针和对象均是const的

}

int main()
{
    t5();

    return 0;
}
