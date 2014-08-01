//
//      mutex / std::lock_guard
//
//      mutex
//          - mutex.lock() or try_lock()
//          - mutex.unlock()
//          - 常通过 unique_lock / lock_guard 实现 exception-safe 。
//
//      lock_guard
//          - mutex wrapper,using RAII-style安全释放 mutex
//

#include <iostream>
#include <thread>
#include <mutex>
#include <map>
using namespace std;

int count=0;
const int loop=100000;
mutex _mutex;

void test_mutex()
{
    for(int i=0;i<loop;i++){
        _mutex.lock(); // lock实现计数性能上不如atomic，这里仅是个例子
        count++;
        _mutex.unlock();
    }
}

// mutex不是可重入的，多次锁定会造成一个死锁
void mutex_simple_dead_lock()
{
    _mutex.lock();
    _mutex.lock();// waiting ... dead-lock
    _mutex.unlock();
    _mutex.unlock();
    cout << "ok" << endl;
}

void test_lock_guard()
{
    for(int i=0;i<loop;i++){
        {
            lock_guard<mutex> guard(_mutex); // get lock
            count++;
        }// release lock
    }
}

int main()
{
    thread t1(test_lock_guard);
    thread t2(test_lock_guard);

    t1.join();
    t2.join();

    cout << "count " << count << endl;

    return 0;
}
