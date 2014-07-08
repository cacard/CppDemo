/*
 *   Template
 */


#include <iostream>
using namespace std;

// Method Template
template <typename T>
int Max(const T x,const T y)
{
    if(x>=y)
    {
        return x;
    }
    return y;
}

int main_5()
{
    int result = Max(1,2);
    cout << result << endl;

    double result2 = Max<double>(1.1,1.2);
    cout << result2 << endl;

    return 0;
}
