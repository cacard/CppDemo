//
//      atomic_flag
//
//      初始状态0 -> test_and_set():1,返回0 -> 继续test_and_set():1，返回1。
//
//      可用来实现一个spin-lock
//

#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic_flag ff = ATOMIC_FLAG_INIT;
int count=0;
const int loop=1000000;

// 使用atomic_floag实现spin-lock和临界区
void thread_safe_using_atomic_flag()
{
    for(int i=0;i<loop;i++){
        while(ff.test_and_set()){} // 如果test_and_set()返回0，则set为1，并进入临界区。其它线程进行test_and_set返回1，则一直循环等待（busy-waiting）
        // ff -> 1
        count++;
        ff.clear(); // ff -> 0 其它线程可获取
    }
}

int main()
{
    // init
    atomic_flag f = ATOMIC_FLAG_INIT;
    bool b = f.test_and_set(); // set and return old value
    cout << "old value ->" << b << endl;

    bool bb = f.test_and_set();
    cout << "new value ->" << bb << endl;

    // spin-lock test
    thread t1(thread_safe_using_atomic_flag);
    thread t2(thread_safe_using_atomic_flag);
    t1.join();
    t2.join();
    cout << "count:" << count << endl;

    return 0;
}




