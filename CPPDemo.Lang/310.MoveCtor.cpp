/*
 *  �ƶ����캯�� move assignment ctor
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

 class Class310
 {
     int age;

public:
    Class310()
        :age(1)
    {
        cout << "-> ctor default" << endl;
    }

    Class310(const Class310& that)
    {
        cout << "-> copy ctor" << endl;
        age = that.age;
    }

    Class310(const Class310&& that) // �ƶ����캯��
    {
        cout << "-> move ctor" << endl;
    }
 };

 int main310()
 {
    Class310 c1;
    Class310 c2(std::move(c1)); // ��c1ͨ��move()���һ����ֵ���ã�ͨ���ƶ����캯����ֵ��c2

    return 0;
 }
