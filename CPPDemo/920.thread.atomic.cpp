//
//      atomic
//
//      .is_lock_free() ȷ��ƽ̨ʵ���Ƿ���lock-free�ġ�
//
//      atomic<int> ���͵�ͬ�� atomic_int
//

#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic<int> count(0);
atomic_int count2(0);
const int loop=100000;

// ʹ��atomicʵ�������ۼ�
void atomic_increase()
{
    for(int i=0;i<loop;i++)
        count++;
}

int main()
{
    // atomic�Ƿ���lock-free��?
    cout << "is atomic lock-free?" << count.is_lock_free() << endl;

    thread t1(atomic_increase);
    thread t2(atomic_increase);
    t1.join();
    t2.join();

    cout << "count:" << count << endl;

    return 0;
}
