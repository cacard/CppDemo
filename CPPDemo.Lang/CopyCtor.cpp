/*
*   �������캯��
*
*   ���ڸ��ƿ���
*   Ĭ����ǳ��¡��ͨ���Զ��塰�������캯������ɶ� new ClassX(ClassX x)�Ķ����¡���ơ�
*   ��ֵ������Ҳ����ʵ�ָ��ƣ��ɸ��Ʋ�����ȥ���塣
*
*/

#include <iostream>
using namespace std;

class Y
{
public:
    int a=0;
    int b=0;

public:
    Y(){}

    Y(Y& y)
    {
        this->a=y.a+1;
        this->b=y.b+1;
    }
};


int main___()
{
    Y* y = new Y();
    Y* _y = new Y(*y);
    Y& yy = *_y;

    cout<<yy.a<<","<<yy.b<<endl;
}




