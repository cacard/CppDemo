//
//  const pointer
//
//  C++ Primer���������top-level const������ָ�룩��low-level const������ָ��ָ��Ķ��󣩡�
//  �ɰ�������һ�����LR(k)�����������������η����������ұߡ�

#include <iostream>
using namespace std;

void t1()
{
    const int a = 1;
}

void t2()
{
    int a = 1;
    int b = 2;
    const int* p = &a; // const ����*p��������ָ��ָ��Ķ���
    //*p = b; // error
    p = &b;

    cout << *p << endl;
}

void t3()
{
    int a = 1;
    int b = 2;
    int const * p = &a; // const����*p
    //*p = b;
    p = &b;

    cout << *p << endl;
}

void t4()
{
    int a = 1;
    int b = 2;
    int* const p = &a; // const����p��������ָ��
    *p = b;
    cout << *p << endl;

    //p = &b;
}

void t5()
{
    int a = 1;
    int b = 2;
    const int * const p = &a; // ָ��Ͷ������const��

}

int main()
{
    t5();

    return 0;
}
