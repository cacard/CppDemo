/*
 *  �������ض���ֵ���������ò���
 *
 *  ��������RVO��Ϊ��
 *
 */

#include <iostream>
#include <cstring>
using namespace std;


class Person
{
public:
    int age=1;

public:
    Person():age(1) // default ctor
    {
        cout << "-> ctor" << endl;
    }

    Person(int a)
        :age(a)
    {
        cout << "-> ctor" << endl;
    }

    Person(const Person& _p) // copy ctor
    {
        cout << "-> copy ctor" << endl;
        age = _p.age;
    }

    Person& operator =(const Person& _p) // copy-assignment operator
    {
        cout << "-> copy assignment operator" << endl;
        if(this==&_p)
        {
            return *this;
        }
        age=_p.age;
        return *this;
    }

    ~Person()
    {
        cout << "~Person" << endl;
    }
};

// #1 ֵ���ݣ�����һ�θ���
void ParamUsingValue(Person p)
{
    cout << p.age << endl;
}

// #2 ���ô��ݣ�����������
void ParamUsingReference(Person& p)
{
    cout << p.age << endl;
}

// #3.1 �������ؾֲ����󣨱������Ż�������ʱ����������
//  * �������ܿ��ܷ���RVO(����ֵ�Ż�)�����ѵ����ߵı���pReturn��ַ���ݸ��ú����������ڲ���p��pReturn��ַ�ϴ���
//  * GUN GCC debug �ϵĽ��������(1)/(2)�ĵ�ַ��ͬ�����������ض���ʱ��δ��������
Person ReturnLocalObject()
{
    Person p;
    p.age=2;
    cout << &p << endl;
    return p;
}

/*  #3.2 �������ؾֲ����󣨱����������Ż���������ʱ����������
 *
 */
 Person ReturnLocalObject2()
 {
     Person p1;
     Person p2;
     bool x;

     return x ? p1 : p2;
 }


//  #4 �������ؾֲ����������
//   ������
//  * ��GUN GCC debug�£����صĶ��������󣬺���������Ȼ���Է��ʡ�
Person& ReturnLocalReference()
{
    Person p;
    cout << &p << endl;
    return p;
}

//  #5 �����ɷ��طǾֲ����������
Person& ReturnNonLocalReference(Person& _p)
{
    return _p;
}

int main()
{
    Person p1;
    Person p2 = ReturnNonLocalReference(p1);
    cout << &p2 << "," << p2.age << endl;

    return 0;
}






