/*
 *   拷贝构造函数
 *
 *  why need?
 *  C++ 是 value semantic 的，对象在“传递”（比如函数传参、函数返回、赋值运算符赋值）时会默认以拷贝一份副本的方式传递！这种拷贝还是浅克隆的方式。
 *  大多数情况下，我们并不需要自己去实现拷贝构造函数，比如对于聚合类（相当于Java中的Pojo）——即成员均为值的情况下。
 *  但若成员包含了指针、引用，那么就需要自定义拷贝构造函数了，不仅仅是拷贝构造函数，相关的复制控制函数（Rule of Three/Five）均需要定义。
 *
 *  how?
 *   默认浅克隆。
 *   赋值操作符也可以实现复制，由赋值操作符定义。
 *
 *   发生场景：#1、#2、#3、#4、#5
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Y
{
public:
    int a=0;
    int b=0;

public:
    Y(){}

    // 拷贝构造函数
    // 假若这里的参数是(const Y y)会发生什么情况？当拷贝发生时，需要调用拷贝构造函数，而这个函数本身又发生一次拷贝。于是又调用拷贝构造函数！
    Y(const Y& y)
    {
        cout << "-> invoked copy ctor" << endl;
        this->a=y.a+1;
        this->b=y.b+1;
    }
};

//  #1 显示调用复制构造函数时
void happens1()
{
    Y y1;
    Y y2(y1);
}

//  #2 值传递的方式传递对象时，发生对象复制
void happens2(Y y)
{

}

//  #3 方法返回对象后，发生临时变量拷贝。注：编译器可能优化，不让其发生
Y happens3()
{
    Y y1;
    Y y2;
    bool b;
    return b?y1:y2;
}

//  #4 使用{}初始化列表时
void happens4()
{
    Y y1;
    Y y2;
    Y yArray[2] = {y1,y2};
}

//  #5 某些类型的方法会发生复制
void happens5()
{
    Y y1;
    vector<Y> v;
    v.push_back(y1);
}

int main()
{
    happens4();
}




