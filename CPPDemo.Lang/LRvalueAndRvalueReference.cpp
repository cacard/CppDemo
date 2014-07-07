/*
 *  Lvalue / Rvalue / Rvalue reference
 *
 *  TODO ��ֵ���ò�֧��
 */

 #include <iostream>
 using namespace std;

 int MethodReturnRValue()
 {
     int temp = 1;
     cout << "temp's address:" << &temp;
     return temp;
 }


 int main()
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
     int && rr = MethodReturnRValue();
     cout << rr << endl;


     return 0;
 }
