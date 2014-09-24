/*
 *  析构函数与虚函数
 *
 *  - Q:为什么析构函数要定义为虚函数？
 *      A:这样，在delete父类指针指向的子类时，就可以先析构子类，再析构父类。否则，只析构父类
 *  - Effective C++ 第7条：要将多态基类的析构函数声明为虚函数
 */


#include <iostream>
using namespace std;

class Base_NoVirtualDtor
{
public:
    ~Base_NoVirtualDtor(){
        cout<<"~Base()"<<endl;
    };
};

class Sub_NoVirtualDtor : public Base_NoVirtualDtor
{
public:
    ~Sub_NoVirtualDtor(){
        cout <<"~Sub()"<<endl;
    };
};

class Base
{
public:
    virtual ~Base(){cout<<"~Base()"<<endl;}; //基类的虚构函数声明为virtual的
};

class Sub : public Base
{
public:
    ~Sub(){cout<<"~Sub()"<<endl;};
};

int main()
{
    // 测试不带virtual的析构函数
    // 结果：只析构父类
    cout << "test case 1 : base calss have no virtual dtor:"<<endl;
    Base_NoVirtualDtor* b = new Sub_NoVirtualDtor();
    delete b;

    // 测试带有virtual的析构函数
    // 结果：先析构子类，再析构父类
    cout << "test case 2 : base calss have virtual dtor:"<<endl;
    Base* c = new Sub();
    delete c;

    return 0;
}
