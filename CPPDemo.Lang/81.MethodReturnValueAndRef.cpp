/*
 *  �������ض���ֵ���������ò���
 *
 *  ��������RVO��Ϊ��
 *
 */

#include <iostream>
#include <cstring>
using namespace std;


class Person81
{
public:
    int age=1;

public:
    Person81():age(1) // default ctor
    {
        cout << "-> ctor" << endl;
    }

    Person81(int a)
        :age(a)
    {
        cout << "-> ctor" << endl;
    }

    Person81(const Person81& _p) // copy ctor
    {
        cout << "-> copy ctor" << endl;
        age = _p.age;
    }

    Person81& operator =(const Person81& _p) // copy-assignment operator
    {
        cout << "-> copy assignment operator" << endl;
        if(this==&_p)
        {
            return *this;
        }
        age=_p.age;
        return *this;
    }

    ~Person81()
    {
        cout << "~Person81" << endl;
    }
};

// #1 ֵ���ݣ�����һ�θ���
void ParamUsingValue(Person81 p)
{
    cout << p.age << endl;
}

// #2 ���ô��ݣ�����������
void ParamUsingReference(Person81& p)
{
    cout << p.age << endl;
}

// #3.1 �������ؾֲ����󣨱������Ż�������ʱ����������
//  * �������ܿ��ܷ���RVO(����ֵ�Ż�)�����ѵ����ߵı���pReturn��ַ���ݸ��ú����������ڲ���p��pReturn��ַ�ϴ���
//  * GUN GCC debug �ϵĽ��������(1)/(2)�ĵ�ַ��ͬ�����������ض���ʱ��δ��������
Person81 ReturnLocalObject()
{
    Person81 p;
    p.age=2;
    cout << &p << endl;
    return p;
}

/*  #3.2 �������ؾֲ����󣨱����������Ż���������ʱ����������
 *
 */
 Person81 ReturnLocalObject2()
 {
     Person81 p1;
     Person81 p2;
     bool x;

     return x ? p1 : p2;
 }


//  #4 �������ؾֲ����������
//   TODO
//  * ��GUN GCC debug�£����صĶ��������󣬺���������Ȼ���Է��ʡ�
Person81& ReturnLocalReference()
{
    Person81 p;
    cout << &p << endl;
    return p;
}

int main81()
{
    Person81 p = ReturnLocalObject();
    cout << &p << "," << p.age << endl;

    return 0;
}






