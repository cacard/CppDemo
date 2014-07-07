/*
*   拷贝构造函数
*
*   属于复制控制
*   默认是浅克隆，通过自定义“拷贝构造函数”完成对 new ClassX(ClassX x)的对象克隆控制。
*   赋值操作符也可以实现复制，由复制操作符去定义。
*
*/

#include <iostream>
using namespace std;

class Y
{
public:
    int a=0;
    int b=0;

public:
    Y(){}

    Y(Y& y)
    {
        this->a=y.a+1;
        this->b=y.b+1;
    }
};


int main___()
{
    Y* y = new Y();
    Y* _y = new Y(*y);
    Y& yy = *_y;

    cout<<yy.a<<","<<yy.b<<endl;
}




