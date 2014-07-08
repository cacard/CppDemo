/*
 * this / *this / 引用
 */

#include <iostream>
using namespace std;

class X
{
private:
    int x=0;

public:
    X()
    {
    }

    // 该函数返回当前实例的一个引用(别名)
    X& BuildChain()
    {
        x++;
        (this->x)++; // 实例内部的this
        return *this; // *this
    }

    void PrintX()
    {
        cout<<"x value:" << x <<endl;
    }
};


/* testing */
int main_1()
{
    X* x = new X();
    X& y = *x; // y 是一个引用
    y.BuildChain().BuildChain(); // y是一个引用，使用.而不是->调用函数
    y.PrintX();

    return 0;
}







