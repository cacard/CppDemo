/*
 *   Template Function
 */


#include <iostream>
using namespace std;

// Function(Method) Template
template <typename T>
int Max(const T x, const T y)
{
    if(x >= y)
    {
        return x;
    }
    return y;
}

int main()
{
    int result = Max(1,2);
    cout << result << endl;

    double result2 = Max<double>(1.1,1.2);
    cout << result2 << endl;

    return 0;
}
