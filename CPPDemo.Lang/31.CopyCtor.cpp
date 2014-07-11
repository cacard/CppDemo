/*
 *   拷贝构造函数
 *
 *  why?
 *      C++ 是 value semantic 的，对象在“传递”（比如函数传参、函数返回）时会默认以拷贝一份副本的方式传递，而且这种拷贝还是浅克隆的。
 *      大多数情况下，默认生成的拷贝构造函数足已（浅拷贝）。并不需要自己去实现拷贝构造函数，比如对于聚合类（相当于Java中的Pojo）——即成员均为值的情况下。
 *      但若成员包含了指针、引用而需要深拷贝时，就需要自定义拷贝构造函数了。不仅仅是拷贝构造函数，相关的复制控制函数（Rule of Three/Five）均需要定义。
 *
 *  how?
 *      默认浅克隆。
 *      自定义实现：
 *          - 值类型直接复制
 *          - 指针类型，先分配内存，再拷贝。
 *
 *  发生场景：
 *      #1、#2、#3、#4、#5
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Resource
{
private:
    size_t len;
    int* data;

public:
    Resource()
        :len(0),data(new int[0])
    {}

    // 拷贝构造函数
    // 假若这里的参数是(const Y y)会发生什么情况？当拷贝发生时，需要调用拷贝构造函数，而这个函数本身又发生一次拷贝。于是又调用拷贝构造函数！
    Resource(const Resource& other)
        :len(other.len),data(new int[other.len])
    {
        cout << "-> copy ctor" << endl;
        std::copy(other.data/*first element*/,other.data+other.len/*last element*/,data/* dest */);
    }

    ~Resource()
    {
        if(data!=NULL){delete[] data;}
        len=0;
    }
};

//  #1 显示调用复制构造函数时
void happens1()
{
    Resource y1;
    Resource y2(y1);
}

//  #2 值传递的方式传递对象时，发生对象复制
void happens2(Resource y)
{
}

//  #3 方法返回对象后，发生临时变量拷贝。注：编译器可能优化，不让其发生
Resource happens3()
{
    Resource y1;
    Resource y2;
    bool b;
    return b?y1:y2;
}

//  #4 使用{}初始化列表时
void happens4()
{
    Resource y1;
    Resource y2;
    Resource yArray[2] = {y1,y2};
}

//  #5 某些类型的方法会发生复制
void happens5()
{
    Resource y1;
    vector<Resource> v;
    v.push_back(y1);
}

int main()
{
    Resource r1;
    happens2(r1);

    return 0;
}




