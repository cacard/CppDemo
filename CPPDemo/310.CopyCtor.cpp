/*
 *   �������캯��
 *
 *  why?
 *      C++ �� value semantic �ģ������ڡ����ݡ������纯�����Ρ��������أ�ʱ��Ĭ���Կ���һ�ݸ����ķ�ʽ���ݣ��������ֿ�������ǳ��¡�ġ�
 *      ���������£�Ĭ�����ɵĿ������캯�����ѣ�ǳ��������������Ҫ�Լ�ȥʵ�ֿ������캯����������ھۺ��ࣨ�൱��Java�е�Pojo����������Ա��Ϊֵ������¡�
 *      ������Ա������ָ�롢���ö���Ҫ���ʱ������Ҫ�Զ��忽�����캯���ˡ��������ǿ������캯������صĸ��ƿ��ƺ�����Rule of Three/Five������Ҫ���塣
 *
 *  how?
 *      Ĭ��ǳ��¡��
 *      �Զ���ʵ�֣�
 *          - ֵ����ֱ�Ӹ���
 *          - ָ�����ͣ��ȷ����ڴ棬�ٿ�����
 *
 *  ����������
 *      #1��#2��#3��#4��#5
 *
 */

#include <iostream>
#include <vector>
using namespace std;

class Resource
{
private:
    size_t len;
    int* data;

public:
    Resource()
        :len(0),data(new int[0])
    {}

    // �������캯��
    // ��������Ĳ�����(const Y y)�ᷢ��ʲô���������������ʱ����Ҫ���ÿ������캯������������������ַ���һ�ο����������ֵ��ÿ������캯����
    Resource(const Resource& other)
        :len(other.len),data(new int[other.len])
    {
        cout << "-> copy ctor" << endl;
        std::copy(other.data/*first element*/,other.data+other.len/*last element*/,data/* dest */);
    }

    ~Resource()
    {
        if(data!=NULL){delete[] data;}
        len=0;
    }
};

//  #1 ��ʾ���ø��ƹ��캯��ʱ
void happens1()
{
    Resource y1;
    Resource y2(y1);
}

//  #2 ֵ���ݵķ�ʽ���ݶ���ʱ������������
void happens2(Resource y)
{
}

//  #3 �������ض���󣬷�����ʱ����������ע�������������Ż��������䷢��
Resource happens3()
{
    Resource y1;
    Resource y2;
    bool b;
    return b?y1:y2;
}

//  #4 ʹ��{}��ʼ���б�ʱ
void happens4()
{
    Resource y1;
    Resource y2;
    Resource yArray[2] = {y1,y2};
}

//  #5 ĳЩ���͵ķ����ᷢ������
void happens5()
{
    Resource y1;
    vector<Resource> v;
    v.push_back(y1);
}

int main()
{
    Resource r1;
    happens2(r1);

    return 0;
}




