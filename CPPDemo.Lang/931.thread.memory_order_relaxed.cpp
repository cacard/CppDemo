//
//      memory_order_relaxed
//
//

#include <iostream>
#include <thread>
#include <atomic>
#include <assert.h>
#include <chrono>
using namespace std;

atomic<int> x,y;

/* relaxed模式下，sotre|store可能发生reorder */
void f_store_store()
{
    x.store(1,memory_order_relaxed);
    y.store(2,memory_order_relaxed);
}

void f_is_y_before_x()
{
    while(y.load(memory_order_relaxed)!=2){cout<<"waiting"<<endl;}
    if(x.load(memory_order_relaxed)==0){
        cout << "catch" << endl; // 可能发生，即y.store可能先于x.store
    }
}

void test()
{
    x=0;
    y=0;
    thread t1(f_store_store);
    thread t2(f_is_y_before_x);
    t1.join();
    t2.join();
}

int main()
{
    for(int i=0;i<999;i++){
        test();
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }

    return 0;
}
