//
//      threadת��
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
    std::thread t2(std::move(t1)); // t1�����е��߳������t2��������t1ʧȥ������

    // ��ʱ������Ҫmove
    std::thread t3 = std::thread(f);

    //t1.join(); // t1�Ѿ���ת�ƣ��޷����к�������
    t2.join();
    t3.join();

    return 0;
}
