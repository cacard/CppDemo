/*
 *  智能指针
 *
 *  shared_ptr
 *  引用计数是指针对象的被引用计数。0时，该对象由指针负责释放。
 *  指针被改变指向其它对象后，原来的对象的计数--。新对象的引用计数++。
 *  指针拷贝后，对象的计数++。
 *  shared_ptr传参（传值而非引用）会发生指针复制，造成对象的引用计数++。
 *  reset() 旧对象引用计数--
 *  reset(new X()) 就对象引用计数--，指向新对象，新对象计数++
 *
 *  unique_ptr
 *  只能指向一个对象。
 *  不可拷贝可赋值。
 *  可转移。
 *
 *  weak_ptr
 *  是 shared_ptr 的辅助指针，作为观察者存在，避免通过 shared_ptr 做观察指针造成的观察依赖。
 *  观察的 shared_ptr 释放资源时，weak_ptr置空。
 *  weak_ptr 并不会增加 shared_ptr 指向对象的引用计数。
 *  weak_ptr 构造  shared_ptr:
 *    * 把 weak_ptr 传递给 shared_ptr 的构造函数，生成一个shared_ptr。
 *    * 使用 weak_ptr 的 lock()。
 *
 */

#include <iostream>
#include <memory>
using namespace std;

class X
{
    string str;

public:
    X()
    {
        cout << "ctor default" << endl;
    }

    X(string _str)
    {
        cout << "ctor(string)" << endl;
        str=_str;
    }

    ~X()
    {
        cout << "~X() ,str=" << str << endl;
    };

    void Print()
    {
        cout << str << endl;
    }
};

void TestSharedPtr()
{
    // string 指针
    shared_ptr<string> pString2 = make_shared<string>("hello");
    if(pString2 && pString2->empty()==false)
    {
        cout << *pString2 << endl;
        cout << "use_count" << pString2.use_count() << endl;
    }

    // 指针拷贝初始化另外一个指针，对象引用计数++
    auto pString3(pString2);
    cout << "pString3:" <<*pString3 << endl;
    cout << "pString3 use_count:" << pString3.use_count() << endl;
    cout << "pString2 use_count:" << pString2.use_count() << endl;

    // 指针赋值，原先的对象计数--（0后释放）；新指向对象的计数++
    shared_ptr<X> px1 = make_shared<X>("px1");
    shared_ptr<X> px2 = make_shared<X>("px2");
    cout << "px use_count(before assignment):" << px1.use_count() << endl;
    // px1原先指向的对象（px1）的被引用计数为1
    // px1被赋值为px2后，对象px1的引用计数变为0，px1释放。
    // px1和px2指向对象的引用计数++，
    px1=px2;
    cout << "px1 use_count:" << px1.use_count() << endl;
    cout << "px2 use_count:" << px2.use_count() << endl;

    // 离开当前scope后，px2释放
}

void M(shared_ptr<X> ptr)
{
    cout << ptr.use_count() << endl;
    cout << "___" << endl;
}

// shared_ptr传参（传值而非引用）会发生指针复制，造成对象的引用计数++
void TestSharedPtrParam()
{
    shared_ptr<X> p = make_shared<X>("x1");
    M(p);
}

void TestReset()
{
    shared_ptr<X> p1 = make_shared<X>("x1");
    shared_ptr<X> p2 = make_shared<X>("x2");
    p2=p1;
    p1.reset(new X("x3"));

    cout << "___" << endl;
}

void TestUniquePtr()
{
    unique_ptr<X> p(new X("x"));
    p->Print();

    p.reset(); // 释放指针
    cout << "after reset" << endl;

    unique_ptr<X> p1(new X("x1"));
    unique_ptr<X> p2(new X("x2"));
    p2 = std::move(p1); // p2指向的对象x2即刻释放

    cout << "___" << endl;
}

void TestWeakPtr()
{
    shared_ptr<X> p1 = make_shared<X>("p1");
    weak_ptr<X> weak1 = p1;
    cout << p1.use_count() << endl;

    shared_ptr<X> p2(weak1);// = shared_ptr<X>(weak1); // #1 使用shared_ptr的构造函数把weak_ptr指针转化成 shared_ptr，引用计数++
    cout << p1.use_count() << endl;

    shared_ptr<X> p3 = weak1.lock(); // #2 使用weak_ptr的lock()返回一个shared_ptr，引用计数++
    cout << weak1.use_count() << endl;
}

int main()
{
    TestReset();

    return 0;
}
