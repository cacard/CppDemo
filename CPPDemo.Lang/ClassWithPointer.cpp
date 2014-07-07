/*
 *  [TODO]  char * µÄÌØÊâĞÔ
 *
 */

#include <iostream>
#include <stdio.h>
using namespace std;

class Person
{
public:
    int * pInt;
    char * pChar="abc";
    int a;

};

int main456()
{
    Person p;
    int a=1;
    char * str = "123";

    p.pInt = &a;
    p.pChar = str;

    printf("%p\r\n",str);
    printf("%p\r\n",p.pChar);

    cout << p.pInt << "," << &(p.pChar) << endl;
}
