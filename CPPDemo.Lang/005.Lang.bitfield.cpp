//
//      bitfield
//

#include <iostream>
using namespace std;

struct _s
{
    unsigned int a:31;
    int b:2;
};

int main()
{
    struct _s s;
    s.a=3;
    cout << s.a << endl;
    cout << sizeof(s) << endl;
    return 0;
}
