/*
 *  cstring 里的 strcpy,memcpy,memset
 *
 *
 */

#include <cstring>
#include <iostream>
using namespace std;

// 根据字符串结束符为结尾进行拷贝
void TestStrCpy()
{
    char * str1 = "abcde";
    char dest[10];

    strcpy(dest,str1);
    cout << dest << endl;
}

// binary copy of the data
void TestMemCpy()
{

}

void TestMemSet()
{

}

