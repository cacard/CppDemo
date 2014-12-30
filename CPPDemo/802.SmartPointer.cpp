/*
 *  ����ָ��
 *
 *  shared_ptr
 *  ���ü�����ָ�����ı����ü�����0ʱ���ö�����ָ�븺���ͷš�
 *  ָ�뱻�ı�ָ�����������ԭ���Ķ���ļ���--���¶�������ü���++��
 *  ָ�뿽���󣬶���ļ���++��
 *  shared_ptr���Σ���ֵ�������ã��ᷢ��ָ�븴�ƣ���ɶ�������ü���++��
 *  reset() �ɶ������ü���--
 *  reset(new X()) �Ͷ������ü���--��ָ���¶����¶������++
 *
 *  unique_ptr
 *  ֻ��ָ��һ������
 *  ���ɿ����ɸ�ֵ��
 *  ��ת�ơ�
 *
 *  weak_ptr
 *  �� shared_ptr �ĸ���ָ�룬��Ϊ�۲��ߴ��ڣ�����ͨ�� shared_ptr ���۲�ָ����ɵĹ۲�������
 *  �۲�� shared_ptr �ͷ���Դʱ��weak_ptr�ÿա�
 *  weak_ptr ���������� shared_ptr ָ���������ü�����
 *  weak_ptr ����  shared_ptr:
 *    * �� weak_ptr ���ݸ� shared_ptr �Ĺ��캯��������һ��shared_ptr��
 *    * ʹ�� weak_ptr �� lock()��
 *
 */

#include <iostream>
#include <memory>
using namespace std;

class X
{
    string str;

public:
    X()
    {
        cout << "ctor default" << endl;
    }

    X(string _str)
    {
        cout << "ctor(string)" << endl;
        str=_str;
    }

    ~X()
    {
        cout << "~X() ,str=" << str << endl;
    };

    void Print()
    {
        cout << str << endl;
    }
};

void TestSharedPtr()
{
    // string ָ��
    shared_ptr<string> pString2 = make_shared<string>("hello");
    if(pString2 && pString2->empty()==false)
    {
        cout << *pString2 << endl;
        cout << "use_count" << pString2.use_count() << endl;
    }

    // ָ�뿽����ʼ������һ��ָ�룬�������ü���++
    auto pString3(pString2);
    cout << "pString3:" <<*pString3 << endl;
    cout << "pString3 use_count:" << pString3.use_count() << endl;
    cout << "pString2 use_count:" << pString2.use_count() << endl;

    // ָ�븳ֵ��ԭ�ȵĶ������--��0���ͷţ�����ָ�����ļ���++
    shared_ptr<X> px1 = make_shared<X>("px1");
    shared_ptr<X> px2 = make_shared<X>("px2");
    cout << "px use_count(before assignment):" << px1.use_count() << endl;
    // px1ԭ��ָ��Ķ���px1���ı����ü���Ϊ1
    // px1����ֵΪpx2�󣬶���px1�����ü�����Ϊ0��px1�ͷš�
    // px1��px2ָ���������ü���++��
    px1=px2;
    cout << "px1 use_count:" << px1.use_count() << endl;
    cout << "px2 use_count:" << px2.use_count() << endl;

    // �뿪��ǰscope��px2�ͷ�
}

void M(shared_ptr<X> ptr)
{
    cout << ptr.use_count() << endl;
    cout << "___" << endl;
}

// shared_ptr���Σ���ֵ�������ã��ᷢ��ָ�븴�ƣ���ɶ�������ü���++
void TestSharedPtrParam()
{
    shared_ptr<X> p = make_shared<X>("x1");
    M(p);
}

void TestReset()
{
    shared_ptr<X> p1 = make_shared<X>("x1");
    shared_ptr<X> p2 = make_shared<X>("x2");
    p2=p1;
    p1.reset(new X("x3"));

    cout << "___" << endl;
}

void TestUniquePtr()
{
    unique_ptr<X> p(new X("x"));
    p->Print();

    p.reset(); // �ͷ�ָ��
    cout << "after reset" << endl;

    unique_ptr<X> p1(new X("x1"));
    unique_ptr<X> p2(new X("x2"));
    p2 = std::move(p1); // p2ָ��Ķ���x2�����ͷ�

    cout << "___" << endl;
}

void TestWeakPtr()
{
    shared_ptr<X> p1 = make_shared<X>("p1");
    weak_ptr<X> weak1 = p1;
    cout << p1.use_count() << endl;

    shared_ptr<X> p2(weak1);// = shared_ptr<X>(weak1); // #1 ʹ��shared_ptr�Ĺ��캯����weak_ptrָ��ת���� shared_ptr�����ü���++
    cout << p1.use_count() << endl;

    shared_ptr<X> p3 = weak1.lock(); // #2 ʹ��weak_ptr��lock()����һ��shared_ptr�����ü���++
    cout << weak1.use_count() << endl;
}

int main()
{
    TestReset();

    return 0;
}
