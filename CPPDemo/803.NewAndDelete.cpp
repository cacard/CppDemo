/*
 *  new / delete �ֶ������ڴ�
 *
 *  new �����Ķ��󣬲�delete�����ͷš�
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


