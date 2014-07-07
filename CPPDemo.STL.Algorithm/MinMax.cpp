/*
 *  Algorithm - min/max
 *
 */

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // max
    int a=1;
    int b=2;
    int c=0;
    c = max<int>(a,b);
    cout << c << endl;

    // max_element
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vector<int>::iterator iterFind = max_element(vec.begin(),vec.end());
    cout << *iterFind << endl;

    return 0;
}
