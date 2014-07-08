/*
 *  移动构造函数 move assignment ctor
 *
 *  通过构造函数拷贝对象，且该对象为右值引用（临时变量、即将销毁的对象）时，调用 move ctor
 */

 #include <iostream>
 using namespace std;

 class Class310
 {
     int age;

public:
    Class310()
        :age(1)
    {
        cout << "-> ctor default" << endl;
    }

    Class310(const Class310& that)
    {
        cout << "-> copy ctor" << endl;
        age = that.age;
    }

    Class310(const Class310&& that) // 移动构造函数
    {
        cout << "-> move ctor" << endl;
    }
 };

 int main310()
 {
    Class310 c1;
    Class310 c2(std::move(c1)); // 把c1通过move()变成一个右值引用，通过移动构造函数赋值给c2

    return 0;
 }
