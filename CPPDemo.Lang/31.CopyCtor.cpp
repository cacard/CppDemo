/*
 *   拷贝构造函数
 *
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

int main31()
{
    happens4();
}




