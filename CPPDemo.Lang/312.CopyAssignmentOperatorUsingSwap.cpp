/*
 *  使用 copy and swap / swap() 实现的拷贝赋值运算符
 *
 *  why using "copy and swap"?
 *      - 异常安全
 *      - 代码复用
 *  how?
 *      - operator(T t) 即采用by-value的方式传参，发送对象拷贝
 *      - 自定义swap(T& x,T& y){ using std::swap; swap()各个成员变量和指针 }
 *      - operator(T t) 中调用 swap(T&,T&)
 */

#include <iostream>
using namespace std;

class R
{
    size_t len;
    int* data;
public:
    // ctor default
    R()
        :len(0),data(new int[0])
    {
        cout<<"ctor()"<<endl;
    }

    R(int _len)
        :len(_len),data(new int[_len])
    {
        cout<<"ctor(int _len)"<<endl;

        // 赋值
        for(int i=0;i<_len;i++)
        {
            data[i]=i;
        }
    }

    // copy ctor
    R(const R& other)
        :len(other.len),data(new int[other.len])
    {
        std::copy(other.data,other.data+other.len,data);
    }

    // 定义swap函数
    void swap(R& x,R& y)
    {
        using std::swap;
        swap(x.len,y.len);
        swap(x.data,y.data);
    }

    // copy assignment operator
    R& operator = (R other) // 注意不是引用传递
    {
        cout<<"operator=()"<<endl;
        swap(*this,other);
        return *this;
    }

    ~R()
    {
        if(data!=NULL)
        {
            delete[] data;
        }
        len=0;
    }

    void Print()
    {
        if(data==NULL||len==0)
        {
            cout<<"null"<<endl;
        }
        for(int i=0;i<len;i++)
        {
            cout<<data[i]<<endl;
        }
    }
};

int main()
{
    R r1(5);
    R r2(10);

    r1=r2;
    r1.Print();

    return 0;
}
