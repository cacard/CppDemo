/*
 *  左值Lvalue / 右值Rvalue / 右值引用RvalueReference
 *
 *  Let CodeBlocks supporting C++11:download the last TDM-GCC，note that check out the option for compalier for support C++11.
 */

 #include <iostream>
 using namespace std;

 int MethodReturnRValue()
 {
     int temp = 10;
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
     cout << "rvalue reference:" << endl;
     int &&rr1 = 1;
     cout << rr1 << endl;
     int&& rr2 = MethodReturnRValue();
     cout << rr2 << endl;
     rr2 = std::move(rr1); // 使用 std::move()
     cout << rr2 << endl;

     return 0;
 }
