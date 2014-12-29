/*
 *  Functor ��������
 *  - ������ú���һ������ Functor ����
 *
 *  Lambda
 *
 *  ֵ��������ò���
 */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FunctorAdd_X
{
     int _state; // ״̬
public:
    FunctorAdd_X(int _s):_state(_s){} // ��ʼ��״̬
    int operator()(int y) const
    {
        return y+_state;
    }
};

void TestFunctor()
{
    FunctorAdd_X myAdd(10);
    int z = myAdd(1);
    cout << z << endl;
}



// ʹ���ڲ����labmda�ֱ�ʵ��for_each
void TestUsingLocalClass()
{
    class F
    {
    public:
        void operator()(int x){ cout << "->" << x << endl;}
    };

    vector<int> v;
    for(int i=0;i<10;i++){
        v.push_back(i);
    }

    F f;
    std::for_each(v.cbegin(),v.cend(),f); // using local class
    std::for_each(v.cbegin(),v.cend(),[](int x){ cout<<"-->"<<x<<endl;}); // using lambda
}

void TestLambda()
{
      // �޷���ֵ���޲���
    [](){cout << "I am in lambda." << endl;}();

    // �в������������ݲ���
    [](int x){cout << "x="<< x << endl;}(1);

    // ���õķ�ʽ���ݲ���
    int a=1;
    [](int& x){ cout << "change x to " << ++x << endl;}(a);
    cout << "after change,a=" << a << endl;

    // ֵ���񣬲���ı���ֻ��
    int b=1;
    [=](){cout << " b =" << b << endl;}();

    // ���ò���
    int c=1;
    [&](){cout << " change c to " << ++c << endl;}();
    cout << c << endl;

    // ֵ���������ò���
    int m=1;
    int n=2;
    [=,&n](){++n;/*++m*/;}();
    cout << "m,n="<<m<<","<<n<<endl;

    // �з���ֵ
    int d = []()->int{return 1;}();
    cout << "d = " << d << endl;

    // �з���ֵ���������
    int e = [](){return 1;}();
    cout << "e = " << e << endl;

    // ����һ��������������
    auto GetMax = [](int x,int y){ return x>y?x:y;};
    int f = GetMax(1,2);
    cout << "f = " << f << endl;
}

int main()
{
    TestFunctor();
    return 0;
}


