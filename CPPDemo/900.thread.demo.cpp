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

int counter = 0;
const static int loopCount = 1000000;

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
        for(int i=0; i<loopCount; i++){ counter++; }
}

void thread2()
{
        for(int i=0; i<loopCount; i++){ counter++; }
}

int main()
{
    // #1
    thread t1(thread_function);
    t1.join();

    // #2
    MyClass m;
    thread t2((MyClass())); // 或者 tt((MyClass())) or tt{MyClass()}
    t2.join();

    // #2 lambda exp
    thread t3([](){ cout<< "hello,running in lambda." << endl;});
    t3.join();


    // interleave of two thread
    thread t10(thread1);
    thread t20(thread2);
    t10.join();
    t20.join();
    cout << "counter=" << counter << endl;

    return 0;
}
