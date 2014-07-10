/*
 *  移动赋值运算符
 *
 *  why?
 *  是拷贝赋值运算符的重载。当赋值对象为右值引用时（临时量），调用 move-assignment operator 构造函数。
 *  目的是为了避免临时对象的拷贝，提高性能。
 *
 *  how?
 *      - this == &other 判读
 *      - 释放当前对象的资源
 *      - 根据源对象，重新分配资源并赋值
 *      - 源对象置空
 *      - return *this
 */

#include <iostream>
using namespace std;

class Class320
{
    size_t length;
    int* data;

public:
    Class320()
        :data(new int[0]),length(0)
    {
        cout << "-> default ctor" << endl;
    }

    Class320& operator = (const Class320& that)
    {

        if(this == &that)
        {
            return *this;
        }

        return *this;
    }

    Class320& operator = (Class320&& that) noexcept
    {
        cout << "-> move assignment operator =" << endl;
        // 如果是自身，返回
        if(this == &that)
        {
            return *this;
        }

        // 释放当前对象的资源（即=号左边将要被赋值对象的资源，这些资源是在构造该对象时创建的）
        delete[] data;

        // 将源对象的资源赋值给当前对象，完毕后置空源对象
        data = that.data;
        length = that.length;

        that.data = NULL;
        that.length = 0;

        return *this;
    }

    ~Class320()
    {
        cout << "-> ~" << endl;
    }
};

int main()
{
    Class320 c1;
    Class320 c2;
    c2 = move(c1); // 调用的是“移动赋值运算符”而非“拷贝赋值运算符”。

    return 0;
}

