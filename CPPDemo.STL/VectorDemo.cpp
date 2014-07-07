/*
 *   Vector Demo
 *
 *  + vector 扩容陷阱
 *
 */


#include <iostream>
#include <vector>
using namespace std;

void test1()
{
    vector<int> vInt;

    // add elements
    int i=0;
    for(;i<10;i++)
        vInt.push_back(i);

    // iterator
    vector<int>::iterator iter = vInt.begin();
    while(iter!=vInt.end())
    {
        cout << *iter << endl;
        iter++;
    }
}

int main_1()
{
    test1();

    return 0;
}
