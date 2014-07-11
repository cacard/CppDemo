/*
 *  ʹ�� copy and swap / swap() ʵ�ֵĿ�����ֵ�����
 *
 *  why using "copy and swap"?
 *      - �쳣��ȫ
 *      - ���븴��
 *  how?
 *      - operator(T t) ������by-value�ķ�ʽ���Σ����Ͷ��󿽱�
 *      - �Զ���swap(T& x,T& y){ using std::swap; swap()������Ա������ָ�� }
 *      - operator(T t) �е��� swap(T&,T&)
 */

#include <iostream>
using namespace std;

class R
{
    size_t len;
    int* data;
public:
    // ctor default
    R()
        :len(0),data(new int[0])
    {
        cout<<"ctor()"<<endl;
    }

    R(int _len)
        :len(_len),data(new int[_len])
    {
        cout<<"ctor(int _len)"<<endl;

        // ��ֵ
        for(int i=0;i<_len;i++)
        {
            data[i]=i;
        }
    }

    // copy ctor
    R(const R& other)
        :len(other.len),data(new int[other.len])
    {
        std::copy(other.data,other.data+other.len,data);
    }

    // ����swap����
    void swap(R& x,R& y)
    {
        using std::swap;
        swap(x.len,y.len);
        swap(x.data,y.data);
    }

    // copy assignment operator
    R& operator = (R other) // ע�ⲻ�����ô���
    {
        cout<<"operator=()"<<endl;
        swap(*this,other);
        return *this;
    }

    ~R()
    {
        if(data!=NULL)
        {
            delete[] data;
        }
        len=0;
    }

    void Print()
    {
        if(data==NULL||len==0)
        {
            cout<<"null"<<endl;
        }
        for(int i=0;i<len;i++)
        {
            cout<<data[i]<<endl;
        }
    }
};

int main()
{
    R r1(5);
    R r2(10);

    r1=r2;
    r1.Print();

    return 0;
}
