/*
 *  Functor 函数对象
 *  - 可像调用函数一样操作 Functor 对象。
 *
 *  Lambda
 *
 *  值捕获和引用捕获。
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FunctorAdd_X
{
     int _state; // 状态
public:
    FunctorAdd_X(int _s):_state(_s){} // 初始化状态
    int operator()(int y) const
    {
        return y+_state;
    }
};

void TestFunctor()
{
    FunctorAdd_X myAdd(10);
    int z = myAdd(1);
    cout << z << endl;
}



// 使用内部类和labmda分别实现for_each
void TestUsingLocalClass()
{
    class F
    {
    public:
        void operator()(int x){ cout << "->" << x << endl;}
    };

    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }

    F f;
    std::for_each(v.cbegin(),v.cend(),f); // using local class
    std::for_each(v.cbegin(),v.cend(),[](int x){ cout<<"-->"<<x<<endl;}); // using lambda
}

void TestLambda()
{
      // 无返回值、无参数
    [](){cout << "I am in lambda." << endl;}();

    // 有参数，常量传递参数
    [](int x){cout << "x="<< x << endl;}(1);

    // 引用的方式传递参数
    int a=1;
    [](int& x){ cout << "change x to " << ++x << endl;}(a);
    cout << "after change,a=" << a << endl;

    // 值捕获，捕获的变量只读
    int b=1;
    [=](){cout << " b =" << b << endl;}();

    // 引用捕获
    int c=1;
    [&](){cout << " change c to " << ++c << endl;}();
    cout << c << endl;

    // 值捕获混合引用捕获
    int m=1;
    int n=2;
    [=,&n](){++n;/*++m*/;}();
    cout << "m,n="<<m<<","<<n<<endl;

    // 有返回值
    int d = []()->int{return 1;}();
    cout << "d = " << d << endl;

    // 有返回值，但不标出
    int e = [](){return 1;}();
    cout << "e = " << e << endl;

    // 定义一个类似匿名函数
    auto GetMax = [](int x,int y){ return x>y?x:y;};
    int f = GetMax(1,2);
    cout << "f = " << f << endl;
}

int main()
{
    TestFunctor();
    return 0;
}


