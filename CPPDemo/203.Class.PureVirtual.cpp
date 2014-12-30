/*
 *  Pure Virutal : 纯虚函数
 *
 *  - 相当于接口
 *  - 含有PureVirtual函数的类称为AbstractClass，不能够实例化
 *  - 派生类如果完全实现了抽象基类，本身才不是抽象类
 */


#include <iostream>
using namespace std;

// abstract class
class Base
{
public:
    virtual void PureVirtualMethod() = 0;
};

class Sub : Base
{
public:
    virtual void PureVirtualMethod(){
        cout << "hello" << endl;
    }
};


int main()
{
    // Base b; // 抽象类不能够实例化
    Sub sub;
    sub.PureVirtualMethod();
    return 0;
}

