/**
* ���е� this / *this / ����
*
* @author licunqing
*
*/

#include <iostream>
using namespace std;

class X
{
private:
    int x=0;

public:
    X()
    {
    }

    // �ú������ص�ǰʵ����һ������(����)
    X& BuildChain()
    {
        x++;
        (this->x)++; // ʵ���ڲ���this
        return *this; // *this
    }

    void PrintX()
    {
        cout<<"x value:" << x <<endl;
    }
};


/* testing */
int main_1()
{
    X* x = new X();
    X& y = *x; // y ��һ������
    y.BuildChain().BuildChain(); // y��һ�����ã�ʹ��.������->���ú���
    y.PrintX();

    return 0;
}







