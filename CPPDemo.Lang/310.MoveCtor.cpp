/*
 *  �ƶ����캯���� move ctor
 *
 *  why?
 *  C++������ value semantic �ġ����󿽱������ںܶ�����£��ر���һЩ��ʱ���У����纯�����ؾֲ��������󣩣����ֿ���Ӱ�������Ҳ���Ҫ��
 *  ���ǣ�C++11������rvalue reference�Լ��ƶ����塣Ŀ�����ü������ٵ���ʱ������������ֱ������ʹ�ã������Ƕ������ж��ο�����
 *
 *  how?
 *  ͨ�����캯�����������Ҹö���Ϊ��ֵ���ã���ʱ�������������ٵĶ���ʱ������ move ctor
 */

 #include <iostream>
 using namespace std;

 class Resource
 {
     int age;

public:
    Resource()
        :age(1)
    {
        cout << "-> ctor default" << endl;
    }

    Resource(const Resource& that)
    {
        cout << "-> copy ctor" << endl;
        age = that.age;
    }

    Resource(const Resource&& that) // �ƶ����캯��
    {
        cout << "-> move ctor" << endl;
    }
 };

 int main310()
 {
    Resource c1;
    Resource c2(std::move(c1)); // ��c1ͨ��move()���һ����ֵ���ã�ͨ���ƶ����캯����ֵ��c2

    return 0;
 }
