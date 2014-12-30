//
//      参数传递
//
//
//      引用传递
//          - std::ref()
//

#include <iostream>
#include <thread>
#include <string>
using namespace std;

void f(int a,int& b)
{
    a++;
    b++;
}

int main()
{
    int x=0;
    int y=0;

    thread t(f,x,std::ref(y));
    t.join();
    cout << "x:" << x << ",y:" << y << endl;

    return 0;
}
