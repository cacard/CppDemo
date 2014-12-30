//
//      memory order : SC
//
//      - default order
//

#include <iostream>
#include <atomic>
#include <thread>
using namespace std;

atomic<int> count(0);
atomic<int> x(0);
atomic<int> y(0);


void f1()
{
    x.store(1);
    y.store(2);
}
void f2()
{
    cout << "x:" << x.load() << ",y:" << y.load() << endl;
}
void test_store_store()
{
    thread t1(f1);
    thread t2(f2);
    t1.join();
    t2.join();
}

void f3()
{
    x.store(1);
    cout << "y:" << y.load() << endl;
}
void f4()
{
    y.store(2);
    cout << "x:" << x.load() << endl;
}

void test_store_load_diffrent_address()
{
    thread t1(f3);
    thread t2(f4);
    t1.join();
    t2.join();
}

int main()
{
    test_store_load_diffrent_address();

    return 0;
}
