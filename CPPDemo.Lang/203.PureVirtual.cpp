/*
 *  Pure Virutal : ���麯��
 *
 *  - �൱�ڽӿ�
 *  - ����PureVirtual���������ΪAbstractClass�����ܹ�ʵ����
 *  - �����������ȫʵ���˳�����࣬����Ų��ǳ�����
 */


#include <iostream>
using namespace std;

// abstract class
class Base
{
public:
    virtual void PureVirtualMethod() = 0;
};

class Sub : Base
{
public:
    virtual void PureVirtualMethod(){
        cout << "hello" << endl;
    }
};


int main()
{
    // Base b; // �����಻�ܹ�ʵ����
    Sub sub;
    sub.PureVirtualMethod();
    return 0;
}

