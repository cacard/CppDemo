/*
 *  explicit ��ֹ��ʽ����ת��
 *
 *  �����ʹ�øùؼ��֣��Դﵽ������ʽת����Ŀ�ġ�
 */

 #include <iostream>
 using namespace std;

 class ClassDemo
 {
 private:
    string name;
 public:
    ClassDemo()
    {

    }

    /*explicit*/ ClassDemo(string str)
    {
        this->name=str;
    }

    void MethodNeedClassDemo(ClassDemo demo)
    {
        cout << demo.name << endl;
    }
 };


 int main15()
 {
     ClassDemo classDemo;
     string name="jack";

     classDemo.MethodNeedClassDemo(name); /* ԭ������Ҫ���� ClassDemo ���ͣ����Ҵ��ݽ�ȥ��һ��string�����ҵ��óɹ���
                                             ����ΪClassDemo�и�����string�Ĺ��캯���������ɴ˹��캯������ʽ��ת�������͡� */

 }
