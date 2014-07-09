/*
 *  new / delete 手动管理内存
 *
 *  new 创建的对象，不delete不会释放。
 */

#include <iostream>
#include "MyClass.hpp" // do not link and and compile
using namespace std;

void TestRelease()
{
    MyClass* p = new MyClass;
    delete p;

    cout << "___" << endl;
}

int main()
{
    TestRelease();
    return 0;
}


