//
//  std::thread(C++ 11) demo
//
//  调用
//      - 普通函数
//      - operator()(){}类
//      - lambda


#include <iostream>
#include <thread>
using namespace std;

int counter=0;
const static int loopCount=1000000;

// 普通函数供thread调用
void thread_function()
{
    cout << "hello,this is runing in the new thread" << endl;
}

// 实现了 operator () 的类供thread调用
class MyClass
{
public:
    void operator()()
    {
        cout << "hello,running in the operator()(){}" << endl;
    }
};

void thread1()
{
        for(int i=0;i<loopCount;i++){ counter++;}
}

void thread2()
{
        for(int i=0;i<loopCount;i++){ counter++;}
}

int main()
{
    // #1
    thread t(thread_function);
    t.join();

    // #2
    MyClass m;
    thread tt((MyClass())); // 或者 tt((MyClass())) or tt{MyClass()}
    tt.join();

    // #2 lambda exp
    thread ttt([](){cout<<"hello,running in lambda."<<endl;});
    ttt.join();





    // interleave of two thread
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    cout << "counter=" << counter << endl;

    return 0;
}
