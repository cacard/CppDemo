/*
 *  ctor ���� ctor
 *
 *  #1 ��ʹ�����Ƴ�ʼ���б����ʽ ClassX():ClassX(...)�����治�ܸ���Ա��ʼ���б�
 *  #2 �ڹ��캯���ڲ�ʹ�� new (this)ClassX(...)
 */

#include <iostream>

 class X
 {
 private:
    int a=2;
    int b;

 public:
     /* ����#1 */
    X():X(3)
    {
        std::cout << "ctor(),a="<< a << std::endl;
    }

    X(int a):a(a),b(1)
    {
        std::cout << "ctor(int)" << std::endl;
        //this->a=a;
    }

    /*
    ���ֵ��÷�ʽ�ǲ���ȷ�ġ�
    X()
    {
        X(11);
    }
    */

    /* ����#2 */
    /*
    X()
    {

        new (this)X(5);
    }
    */

    void Print()
    {
        std::cout << "x = " << a << std::endl;
    }
 };

int main12()
{
    X x;
    x.Print();

    return 0;
}
