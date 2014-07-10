/*
 *   拷贝赋值操作符： copy assignment operator
 *
 *  注1：赋值操作符并不是“构造函数”
 *  注2：名称中的“copy”意味着与拷贝相关，在函数内部实现拷贝。
 *
 *  why?
 *      当使用“=号”赋值时，包含了拷贝的意思。比较特殊的地方是，在对象赋新值之前，如果处理旧有对象。
 *      通过自定义赋值运算符重载，完成对旧有对象的释放和对源对象的拷贝。
 *
 *  how?
 *      属于复制控制。
 *      默认情况下会生成一个，浅克隆。
 *      自定义实现：
 *          如果是赋值自身，返回；
 *          释放旧资源；
 *          赋值新资源；
 *          返回；
 */

#include <iostream>
using namespace std;

class Resource
{
private:
    size_t len;
    int* data;

public:
    Resource()
        :len(0),data(new int[0])
    {
        cout << "->ctor default" << endl;
    }

    // 赋值运算符重载
    //  如果参数是(const Resource other)会发生什么？
    //      会在调用该函数时发生一次没有必要的对象拷贝（即调用了 copy ctor）。
    //  如果返回值是Resource而不是Resource&会发生什么？
    //      会发生一次对象拷贝。
    Resource& operator =(const Resource& other)
    {
        cout << "-> operator = ()" << endl;

        if(this==&other) // 如果是自身，立即返回
        {
            cout << "copy your self" << endl;
            return *this;
        }

        delete[] data;
        len=other.len;
        data=new int[len];
        std::copy(other.data/*first element*/,other.data+other.len/*last element*/,data/* dest */);

        return *this;
    }


    ~Resource()
    {
        delete[] data;
        cout << "~Resource()" << endl;
    }
};


int main()
{
    Resource r1;
    Resource r2;
    r1= r2;

    /* 这种写法是通过拷贝构造函数进行复制的，而不是通过赋值操作符。*/
    /*
    Resource r1;
    Resource r2 = r1; // 等价于 Resource r2(r1);
    */

    cout << &r1 << "," << & r2 << endl; // 0x28fefc,0x28fef8

    return 0;
}
