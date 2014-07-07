/*
 *  重载
 *
 *  注意const重载
 *      const可分为 top-level（指向对象本身）/low-level（指向对象的引用）。
 *
 */

 #include <iostream>
 using namespace std;

 class Y{};

 /* 下面两个函数具有相同语义，即a均是值拷贝，无法改变实参。 */
 void Method1(int a){}
 //void Method1(const int a){} // error:redefinition

  /* 同样的语义，对象拷贝 */
 void Method2(Y y){}
 //void Method2(const Y y){} // error:redefinition

 /* 下面两个函数具有不同语义，即后者无法改变实参，之所以使用引用，可能是因为不想拷贝，节省内存。 */
 void Method3(int& a){}
 void Method3(const int& a){}

 void Method4(Y& y){}
 void Method4(const Y& y){}

 int main11(int count,char * args[])
 {
     return 0;
 }
