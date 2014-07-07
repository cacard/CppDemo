/*
 *  explicit 防止隐式类型转换
 *
 *  建议均使用该关键字，以达到必须显式转换的目的。
 */

 #include <iostream>
 using namespace std;

 class ClassDemo
 {
 private:
    string name;
 public:
    ClassDemo()
    {

    }

    /*explicit*/ ClassDemo(string str)
    {
        this->name=str;
    }

    void MethodNeedClassDemo(ClassDemo demo)
    {
        cout << demo.name << endl;
    }
 };


 int main15()
 {
     ClassDemo classDemo;
     string name="jack";

     classDemo.MethodNeedClassDemo(name); /* 原函数需要的是 ClassDemo 类型，但我传递进去了一个string，而且调用成功。
                                             是因为ClassDemo有个基于string的构造函数，可以由此构造函数“隐式”转换成类型。 */

 }
