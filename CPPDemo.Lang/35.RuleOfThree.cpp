/*
 *  Rule of Three
 *
 *  why need?
 *  Q:何时需要自定义析构函数或者复制、赋值函数？
 *  A:当类内部包含了资源时（比如int* data）。默认生成的操作是浅拷贝，而我们需要深拷贝。
 *
 *  how?
 *  一般需要同时自定义实现 dtor / copy ctor / copy assignment operator
 *  C++11增加了move语义，变成了 Rule of Five，即还需要实现 move ctor / move assignment operator。
 *
 *  相关移步到RuleOfFive的具体实现。
 *
 */

 #include <iostream>
 #include <cstring>
 #include <stdio.h>
 using namespace std;

 class Resource
 {
 private:
    size_t len;
    int* data;
public:
    Resource() // default ctor
        :len(0),data(new int[0])
    {
        cout<<"ctor-default"<<endl;
    }

    Resource(int len)   // 带有参数(int)的构造函数
        :data(new int[len]),len(len)
    {
        cout<<"ctor(int)"<<endl;
    }

    Resource(const Resource& other) // #1 拷贝构造函数
        :data(new int[other.len]),len(other.len)
    {
        cout<<"copy ctor(T&)"<<endl;

        // 拷贝构造函数是“构造函数”，表明对象正在初始化。放到初始化列表中初始化。

        // 复制
        std::copy(other.data/*first element*/,other.data+other.len/*last element*/,data/* dest */);

    }

    Resource& operator = (const Resource& other) // #2 赋值运算符重载
    {
        cout<<"operator=()"<<endl;
        // 如果是自身赋值给自身，立即返回
        if(this == &other)
        {
            return *this;
        }

        // 注意，此时*this是被赋值的对象，该对象或许刚刚初始化完毕（data长度0），
        // 也获取已经分配资源（data长度不为0）。无论如何，需要重新分配资源。

        // 释放旧资源
        delete[] data;
        len=0;

        // 分配新资源，并从源中拷贝
        len=other.len;
        data=new int[len];
        std::copy(other.data/*first element*/,other.data+other.len/*last element*/,data/* dest */);

        return *this;
    }

    ~Resource() // 3 析构
    {
        cout<<"~T()"<<endl;
        if(data!=NULL)
        {
            delete[] data;
        }

        len=0;
    }
 };

void TestCtor()
{
    Resource r1;
    Resource r2(10);
    Resource r3(r2);
}

void TestAssignment()
{
    Resource r1(10);
    Resource r2(20);

    r1 = r2;
}

int main()
{
    TestAssignment();
    return 0;
}
