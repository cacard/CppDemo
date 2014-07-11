/*
 *  �ƶ����캯���� move ctor
 *
 *  why?
 *  C++������ value semantic �ġ����󿽱������ںܶ�����£��ر���һЩ��ʱ���У����纯�����ؾֲ��������󣩣����ֿ���Ӱ�������Ҳ���Ҫ��
 *  ���ǣ�C++11������rvalue reference�Լ��ƶ����塣Ŀ�����ü������ٵ���ʱ������������ֱ������ʹ�ã������Ƕ������ж��ο�����
 *
 *  how?
 *  ͨ�����캯�����������Ҹö���Ϊ��ֵ���ã���ʱ�������������ٵĶ���ʱ�������ƶ����캯����
 *      - ��Դ����ĳ�Ա��ֵ���¶���
 *      - Դ�����Ա�ÿ�
 */

 #include <iostream>
 using namespace std;

 class Resource
 {
private:
    size_t len;
    int* data;
public:
    Resource()
        :len(0),data(new int[0])
    {
        cout << "-> ctor default" << endl;
    }

    Resource(const Resource& other)
    {
        cout << "-> copy ctor" << endl;
        len=other.len;
        std::copy(other.data,other.data+len,data);
    }

    Resource(Resource&& other) // �ƶ����캯��
    {
        cout << "-> move ctor" << endl;
        len=other.len;
        data=other.data;
        // �ÿ�
        other.len=0;
        other.data=NULL;
    }
 };

 int main()
 {
    Resource c1;
    Resource c2(std::move(c1)); // ��c1ͨ��move()���һ����ֵ���ã�ͨ���ƶ����캯����ֵ��c2

    return 0;
 }
