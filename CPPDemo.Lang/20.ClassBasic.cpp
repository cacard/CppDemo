/*
*   Class Simple Demo
*/

#include <iostream>
#include <stdio.h>
using namespace std;

class ClassSimple
{
private:
    int age;
    const int constAge=0;
    char * name; // C Style String
    static int staticValue; // 静态变量

public:
    ClassSimple() // ctor1 default
        :age(1),name("default name"),constAge(1) // 成员变量初始化列表，非静态成员均在此初始化
    { // 进入ctor内部后，变量已完成初始化。以下均是再次赋值。
        cout << "ctor default" << endl;

        this->age=-1;
        name="no name";
    }

    ClassSimple(int v) // ctor2
        :age(v),constAge(-3)
    {
    }

    ~ClassSimple() // dtor
    {
        cout << "~ClassSimple()" << endl;
    }

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

    // 实例方法可访问静态变量
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
void ClassSimple::SayHelloAgain()
{
    printf("hello again.\r\n");
}

// 静态变量的初始化必须放在类型外部，且没有必要声明为static
int ClassSimple::staticValue=0;


void Test1()
{
    ClassSimple* c1 = new ClassSimple(); // 创建类
    (*c1).SayHello(); // 方法调用1
    c1->SayHello(); //方法调用2

    c1->SetAge(1);
    int age = c1->GetAge();
    printf("age:%d\r\n",age);
    c1->PrintName();

    ClassSimple * c2 = new ClassSimple(1);
    printf("age:%d\r\n",c2->GetAge());

    c2->SayHelloAgain();

    // static member
    c2->SetStaticValue(11);
    c2->PrintStaticValue();

    // static method
    ClassSimple::StaticMethod();

    // release
    delete c1;
    delete c2;
}

void Test2()
{
    // C++11 推荐使用下列方式
    ClassSimple c1;
    ClassSimple c2;

}


int main20()
{
    return 0;
}








