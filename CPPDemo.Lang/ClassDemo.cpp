/*
*   Class Demo
*/

#include <iostream>
#include <stdio.h>
using namespace std;

class ClassOne
{

/* fields */
private:
    int age;
    const int constAge=0;
    char * name;
    static int staticValue; // ��̬����

/* ctor */
public:
    ClassOne()
    {
        cout << "ctor" << endl;
        this->age=-1;
        name="no name";
    }
    ClassOne(int v):age(v),constAge(-3) // ���캯���ġ���Ա��ʼ���б�
    {
    }

    ~ClassOne()
    {
        cout << "~ClassOne()" << endl;
    }

/* methods */
public:
    void SayHello()
    {
        printf("Hello.");
    }

    void SetAge(int age)
    {
        this->age=age;
    }

    int GetAge()
    {
        return this->age;
    }

    void PrintName()
    {
        printf("name:%s\r\n",this->name);
    }

    // �������������ⲿʵ��
    void SayHelloAgain();

    void SetStaticValue(int value)
    {
        staticValue=value;
    }
    void PrintStaticValue()
    {
        printf("static value:%d\r\n",staticValue);
    }

    // ��̬����
    void static StaticMethod()
    {
        printf("this is static method,staticValue=%d\r\n",staticValue);
    }
};

// ��class�ⲿ����method�����������ڲ������÷�����
void ClassOne::SayHelloAgain()
{
    printf("hello again.\r\n");
}

// ��̬�����ĳ�ʼ��
int ClassOne::staticValue=0;




void test1()
{
    ClassOne * classOne = new ClassOne(); // ������
    (*classOne).SayHello(); // ��������1
    classOne->SayHello(); //��������2

    classOne->SetAge(1);
    int age = classOne->GetAge();
    printf("age:%d\r\n",age);
    classOne->PrintName();

    ClassOne * classOne2 = new ClassOne(1);
    printf("age:%d\r\n",classOne2->GetAge());

    classOne->SayHelloAgain();

    // static member
    classOne->SetStaticValue(11);
    classOne->PrintStaticValue();

    // static method
    ClassOne::StaticMethod();

    // release
    delete classOne;
    delete classOne2;
}

void test2()
{
    ClassOne one;

}

/* ���� */
int main_0()
{
    test2();

    return 0;
}








