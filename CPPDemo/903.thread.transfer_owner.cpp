//
//      thread转移
//
//      - movable
//      - non-copyable
//

#include <iostream>
#include <thread>

void f()
{
    std::cout << "f()" << std::endl;
}

int main()
{
    std::thread t1(f);
    std::thread t2(std::move(t1)); // t1中运行的线程与变量t2关联，与t1失去关联。

    // 临时量不需要move
    std::thread t3 = std::thread(f);

    //t1.join(); // t1已经被转移，无法进行后续操作
    t2.join();
    t3.join();

    return 0;
}
