/*
 *  移动构造函数： move ctor
 *
 *  why?
 *  C++语言是 value semantic 的。对象拷贝发生在很多情况下，特别是一些临时量中（比如函数返回局部变量对象），这种拷贝影响性能且不必要。
 *  于是，C++11引入了rvalue reference以及移动语义。目的是让即将销毁的临时对象获得重生，直接拿来使用，而不是对它进行二次拷贝。
 *
 *  how?
 *  通过构造函数拷贝对象，且该对象为右值引用（临时变量、即将销毁的对象）时，调用 move ctor
 */

 #include <iostream>
 using namespace std;

 class Resource
 {
     int age;

public:
    Resource()
        :age(1)
    {
        cout << "-> ctor default" << endl;
    }

    Resource(const Resource& that)
    {
        cout << "-> copy ctor" << endl;
        age = that.age;
    }

    Resource(const Resource&& that) // 移动构造函数
    {
        cout << "-> move ctor" << endl;
    }
 };

 int main310()
 {
    Resource c1;
    Resource c2(std::move(c1)); // 把c1通过move()变成一个右值引用，通过移动构造函数赋值给c2

    return 0;
 }
