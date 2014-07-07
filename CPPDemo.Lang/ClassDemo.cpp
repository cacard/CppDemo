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
    static int staticValue; // 静态变量

/* ctor */
public:
    ClassOne()
    {
        cout << "ctor" << endl;
        this->age=-1;
        name="no name";
    }
    ClassOne(int v):age(v),constAge(-3) // 构造函数的“成员初始化列表”
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

    // 函数声明，在外部实现
    void SayHelloAgain();

    void SetStaticValue(int value)
    {
        staticValue=value;
    }
    void PrintStaticValue()
    {
        printf("static value:%d\r\n",staticValue);
    }

    // 静态函数
    void static StaticMethod()
    {
        printf("this is static method,staticValue=%d\r\n",staticValue);
    }
};

// 在class外部定义method（必须在类内部声明该方法）
void ClassOne::SayHelloAgain()
{
    printf("hello again.\r\n");
}

// 静态变量的初始化
int ClassOne::staticValue=0;




void test1()
{
    ClassOne * classOne = new ClassOne(); // 创建类
    (*classOne).SayHello(); // 方法调用1
    classOne->SayHello(); //方法调用2

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

/* 测试 */
int main_0()
{
    test2();

    return 0;
}








