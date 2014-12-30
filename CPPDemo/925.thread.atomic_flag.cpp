//
//      atomic_flag
//
//      ��ʼ״̬0 -> test_and_set():1,����0 -> ����test_and_set():1������1��
//
//      ������ʵ��һ��spin-lock
//

#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic_flag ff = ATOMIC_FLAG_INIT;
int count=0;
const int loop=1000000;

// ʹ��atomic_floagʵ��spin-lock���ٽ���
void thread_safe_using_atomic_flag()
{
    for(int i=0;i<loop;i++){
        while(ff.test_and_set()){} // ���test_and_set()����0����setΪ1���������ٽ����������߳̽���test_and_set����1����һֱѭ���ȴ���busy-waiting��
        // ff -> 1
        count++;
        ff.clear(); // ff -> 0 �����߳̿ɻ�ȡ
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




