/*
 *  Rule of Three
 *
 *  why need?
 *  Q:��ʱ��Ҫ�Զ��������������߸��ơ���ֵ������
 *  A:�����ڲ���������Դʱ������int* data����Ĭ�����ɵĲ�����ǳ��������������Ҫ�����
 *
 *  how?
 *  һ����Ҫͬʱ�Զ���ʵ�� dtor / copy ctor / copy assignment operator
 *  C++11������move���壬����� Rule of Five��������Ҫʵ�� move ctor / move assignment operator��
 *
 *  ����Ʋ���RuleOfFive�ľ���ʵ�֡�
 *
 */

 #include <iostream>
 #include <cstring>
 #include <stdio.h>
 using namespace std;

 class Resource
 {
 private:
    size_t len;
    int* data;
public:
    Resource() // default ctor
        :len(0),data(new int[0])
    {
        cout<<"ctor-default"<<endl;
    }

    Resource(int len)   // ���в���(int)�Ĺ��캯��
        :data(new int[len]),len(len)
    {
        cout<<"ctor(int)"<<endl;
    }

    Resource(const Resource& other) // #1 �������캯��
        :data(new int[other.len]),len(other.len)
    {
        cout<<"copy ctor(T&)"<<endl;

        // �������캯���ǡ����캯�����������������ڳ�ʼ�����ŵ���ʼ���б��г�ʼ����

        // ����
        std::copy(other.data/*first element*/,other.data+other.len/*last element*/,data/* dest */);

    }

    Resource& operator = (const Resource& other) // #2 ��ֵ���������
    {
        cout<<"operator=()"<<endl;
        // ���������ֵ��������������
        if(this == &other)
        {
            return *this;
        }

        // ע�⣬��ʱ*this�Ǳ���ֵ�Ķ��󣬸ö������ոճ�ʼ����ϣ�data����0����
        // Ҳ��ȡ�Ѿ�������Դ��data���Ȳ�Ϊ0����������Σ���Ҫ���·�����Դ��

        // �ͷž���Դ
        delete[] data;
        len=0;

        // ��������Դ������Դ�п���
        len=other.len;
        data=new int[len];
        std::copy(other.data/*first element*/,other.data+other.len/*last element*/,data/* dest */);

        return *this;
    }

    ~Resource() // 3 ����
    {
        cout<<"~T()"<<endl;
        if(data!=NULL)
        {
            delete[] data;
        }

        len=0;
    }
 };

void TestCtor()
{
    Resource r1;
    Resource r2(10);
    Resource r3(r2);
}

void TestAssignment()
{
    Resource r1(10);
    Resource r2(20);

    r1 = r2;
}

int main()
{
    TestAssignment();
    return 0;
}
