/*
 *  ����
 *
 *  ע��const����
 *      const�ɷ�Ϊ top-level��ָ�������/low-level��ָ���������ã���
 *
 */

 #include <iostream>
 using namespace std;

 class Y{};

 /* ������������������ͬ���壬��a����ֵ�������޷��ı�ʵ�Ρ� */
 void Method1(int a){}
 //void Method1(const int a){} // error:redefinition

  /* ͬ�������壬���󿽱� */
 void Method2(Y y){}
 //void Method2(const Y y){} // error:redefinition

 /* ���������������в�ͬ���壬�������޷��ı�ʵ�Σ�֮����ʹ�����ã���������Ϊ���뿽������ʡ�ڴ档 */
 void Method3(int& a){}
 void Method3(const int& a){}

 void Method4(Y& y){}
 void Method4(const Y& y){}

 int main11(int count,char * args[])
 {
     return 0;
 }
