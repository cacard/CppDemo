/*
 *  TODO Copy and Swap ϰ��
 *
 *  why?
 *      ���Լ�ʵ�ֿ�����ֵ��������ʱ���Լ������ڴ桢��ֵ���ͷž���Դ������һЩ���⣬������������ڴ�����г������쳣����ô�ɶ����״̬�����˸ı䡣�Ҵ���ʮ��ӷ�ס�
 *      ͨ��std::swap���Զ���һ��swap()���ɱ����������⡣
 *
 *  how?
 *
 *
 *  @see http://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
 */

#include <iostream>
using namespace std;

class Class33
{
    int age;

public:
    Class33()
    {
        cout << "ctor" << endl;
    }

    Class33(const Class33& that)
    {
        age=that.age;
    }

/*
    Class33& operator = (const Class33& that) // copy-assignment operator��ʹ������������
    {
        cout << "operator = ref" << endl;
        if(this==&that)
        {
            return *this;
        }
        age=that.age;
        return *this;
    }
*/

    Class33& operator = (Class33 that)// copy-assignment operator��ʹ��ֵ���ݲ���
    {
        cout << "operator = value" << endl;
        std::swap(*this,that);
        return *this;
    }
};

int main37()
{
    Class33 c1;
    Class33 c2;

    c2 = c1 ; //
}
