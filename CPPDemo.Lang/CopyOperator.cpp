/*
 *   ��ֵ������
 *
 *   ���ڸ��ƿ���
 *   Ĭ������»�����һ������ʾ�Զ�����ڴ濽����������ֵ������Statck�ϸ��ƣ���������˼�ǣ�ָ���Աָ��Heap�е�ͬһ�����󣩡�
 *
 */

#include <iostream>
using namespace std;

class Z
{
public:
    int a=0;

public:
    Z(){}

    Z&/*Ҳ������void��ֻ�ǲ�֧��a=b=c*/ operator =(const Z& _z)
    {
        cout << "-> operator = ()" << endl;
        if(this==&_z) // �����������������
        {
            cout << "copy your self" << endl;
            return *this;
        }

        this->a=_z.a+1; //����ʱ��a++
        return *this;
    }

    Z(const Z& _z)
    {
        cout << "-> copy ctor" << endl;
        this->a=_z.a;
    }

    ~Z()
    {
        cout << "~Z()" << endl;
    }
};


int main20()
{
    Z z;
    Z zz;
    zz = z;

    /* ����д����ͨ���������캯�����и��Ƶģ�������ͨ����ֵ��������*/
    /*
    Z z;
    Z zz = z; // �ȼ��� Z zz(z);
    */

    cout << &z << "," << & zz << endl; // 0x28fefc,0x28fef8
    cout << z.a << "," << zz.a << endl; // 1,2

    return 0;
}
