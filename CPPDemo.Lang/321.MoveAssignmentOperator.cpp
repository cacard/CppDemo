/*
 *  �ƶ���ֵ�����
 *
 *  why?
 *  �ǿ�����ֵ����������ء�����ֵ����Ϊ��ֵ����ʱ����ʱ���������� move-assignment operator ���캯����
 *  Ŀ����Ϊ�˱�����ʱ����Ŀ�����������ܡ�
 *
 *  how?
 *      - this == &other �ж�
 *      - �ͷŵ�ǰ�������Դ
 *      - ����Դ�������·�����Դ����ֵ
 *      - Դ�����ÿ�
 *      - return *this
 */

#include <iostream>
using namespace std;

class Class320
{
    size_t length;
    int* data;

public:
    Class320()
        :data(new int[0]),length(0)
    {
        cout << "-> default ctor" << endl;
    }

    Class320& operator = (const Class320& that)
    {

        if(this == &that)
        {
            return *this;
        }

        return *this;
    }

    Class320& operator = (Class320&& that) noexcept
    {
        cout << "-> move assignment operator =" << endl;
        // �������������
        if(this == &that)
        {
            return *this;
        }

        // �ͷŵ�ǰ�������Դ����=����߽�Ҫ����ֵ�������Դ����Щ��Դ���ڹ���ö���ʱ�����ģ�
        delete[] data;

        // ��Դ�������Դ��ֵ����ǰ������Ϻ��ÿ�Դ����
        data = that.data;
        length = that.length;

        that.data = NULL;
        that.length = 0;

        return *this;
    }

    ~Class320()
    {
        cout << "-> ~" << endl;
    }
};

int main()
{
    Class320 c1;
    Class320 c2;
    c2 = move(c1); // ���õ��ǡ��ƶ���ֵ����������ǡ�������ֵ���������

    return 0;
}

