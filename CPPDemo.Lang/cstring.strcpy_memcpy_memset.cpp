/*
 *  cstring ��� strcpy,memcpy,memset
 *
 *
 */

#include <cstring>
#include <iostream>
using namespace std;

// �����ַ���������Ϊ��β���п���
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

