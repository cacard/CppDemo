/*
 *  Lvalue / Rvalue / Rvalue reference
 *
 *  TODO 右值引用不支持
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
     // 普通引用
     int a=1;
     int& ra = a; // ra 是 a 的引用，取地址是相同的
     cout << "a's address:" << &a << ", and ra's address:" << &ra << endl;
     ra=2;
     cout << a << endl;

     // const 引用
     const int b=1;
     const int& rb = b;
     cout << rb << endl; // const 引用只读

     const int& rc = 2; // const引用还可以直接初始化到纯右值上
     cout << rc << endl;

     const int& rd = MethodReturnRValue(); // const引用还可以绑定到一个函数返回的右值上
     cout << rd <<",and rd's address is " << &rd << endl;

     // 右值引用
     int && rr = MethodReturnRValue();
     cout << rr << endl;


     return 0;
 }
