/*
 *  Lvalue / Rvalue / Rvalue reference
 *
 *  let CodeBlocks supported C++11:download the last TDM-GCC��note that check out the option for compalier for support C++11.
 */

 #include <iostream>
 using namespace std;

 int MethodReturnRValue()
 {
     int temp = 10;
     return temp;
 }


 int main90()
 {
     // ��ͨ����
     int a=1;
     int& ra = a; // ra �� a �����ã�ȡ��ַ����ͬ��
     cout << "a's address:" << &a << ", and ra's address:" << &ra << endl;
     ra=2;
     cout << a << endl;

     // const ����
     const int b=1;
     const int& rb = b;
     cout << rb << endl; // const ����ֻ��

     const int& rc = 2; // const���û�����ֱ�ӳ�ʼ��������ֵ��
     cout << rc << endl;

     const int& rd = MethodReturnRValue(); // const���û����԰󶨵�һ���������ص���ֵ��
     cout << rd <<",and rd's address is " << &rd << endl;

     // ��ֵ����
     cout << "rvalue reference:" << endl;
     int &&rr1 = 1;
     cout << rr1 << endl;
     int&& rr2 = MethodReturnRValue();
     cout << rr2 << endl;
     rr2 = std::move(rr1); // ʹ�� std::move()
     cout << rr2 << endl;

     return 0;
 }
