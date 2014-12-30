//
//      atomic
//
//      .is_lock_free() 确认平台实现是否是lock-free的。
//
//      atomic<int> 类型等同于 atomic_int
//

#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic<int> count(0);
atomic_int count2(0);
const int loop=100000;

// 使用atomic实现无锁累加
void atomic_increase()
{
    for(int i=0;i<loop;i++)
        count++;
}

int main()
{
    // atomic是否是lock-free的?
    cout << "is atomic lock-free?" << count.is_lock_free() << endl;

    thread t1(atomic_increase);
    thread t2(atomic_increase);
    t1.join();
    t2.join();

    cout << "count:" << count << endl;

    return 0;
}
