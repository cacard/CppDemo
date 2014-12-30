/*
 *  �����������麯��
 *
 *  - Q:Ϊʲô��������Ҫ����Ϊ�麯����
 *      A:��������delete����ָ��ָ�������ʱ���Ϳ������������࣬���������ࡣ����ֻ��������
 *  - Effective C++ ��7����Ҫ����̬�����������������Ϊ�麯��
 */


#include <iostream>
using namespace std;

class Base_NoVirtualDtor
{
public:
    ~Base_NoVirtualDtor(){
        cout<<"~Base()"<<endl;
    };
};

class Sub_NoVirtualDtor : public Base_NoVirtualDtor
{
public:
    ~Sub_NoVirtualDtor(){
        cout <<"~Sub()"<<endl;
    };
};

class Base
{
public:
    virtual ~Base(){cout<<"~Base()"<<endl;}; //������鹹��������Ϊvirtual��
};

class Sub : public Base
{
public:
    ~Sub(){cout<<"~Sub()"<<endl;};
};

int main()
{
    // ���Բ���virtual����������
    // �����ֻ��������
    cout << "test case 1 : base calss have no virtual dtor:"<<endl;
    Base_NoVirtualDtor* b = new Sub_NoVirtualDtor();
    delete b;

    // ���Դ���virtual����������
    // ��������������࣬����������
    cout << "test case 2 : base calss have virtual dtor:"<<endl;
    Base* c = new Sub();
    delete c;

    return 0;
}
