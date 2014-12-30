//
//      join / joinable / detach
//
//      join
//          - 调用方等待thread结束，并释放其资源。
//
//      detach
//          - 不再关注thread，让其后台自有运行。
//          - joinable() == false
//

#include <iostream>
#include <thread>
#include <chrono> // C++11 Date
using namespace std;

void f()
{
    std::thread::id id = std::this_thread::get_id();
    cout << "current thread's id:" << id << endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}

int main()
{
    thread t(f);
    bool isJoinable = t.joinable();
    cout << "isJoinable:" << isJoinable << endl;
    t.detach();
    cout << "isJoinable:" << t.joinable() << endl;
    //t.join();

}
