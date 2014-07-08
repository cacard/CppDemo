/*
 *  ctor 调用 ctor
 *
 *  #1 可使用类似初始化列表的形式 ClassX():ClassX(...)，后面不能跟成员初始化列表
 *  #2 在构造函数内部使用 new (this)ClassX(...)
 */

#include <iostream>

 class X
 {
 private:
    int a=2;
    int b;

 public:
     /* 方法#1 */
    X():X(3)
    {
        std::cout << "ctor(),a="<< a << std::endl;
    }

    X(int a):a(a),b(1)
    {
        std::cout << "ctor(int)" << std::endl;
        //this->a=a;
    }

    /*
    这种调用方式是不正确的。
    X()
    {
        X(11);
    }
    */

    /* 方法#2 */
    /*
    X()
    {

        new (this)X(5);
    }
    */

    void Print()
    {
        std::cout << "x = " << a << std::endl;
    }
 };

int main12()
{
    X x;
    x.Print();

    return 0;
}
