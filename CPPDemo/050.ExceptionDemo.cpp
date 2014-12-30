/*
*   Exception
*/

#include <iostream>
using namespace std;

// 该函数可能抛异常并带有声明
void methodMayException_int() throw (char *, int) // 可能抛出的异常声明
{
    throw 1; // 最终抛出的是int
}
void methodMayException_char() throw (char *, int)
{
    char* s = "some exception happend";
    throw s; // 最终抛出的是char*。这里不要直接抛字符串字面值
}

void testException()
{
    try
    {
        throw "some exceptions";
    }
    catch(const char * e)
    {
        cout << e << endl;
    }
    finally:
    {
        cout << "finally" << endl;
    }
}

void testException2()
{
    try
    {
        methodMayException_char();
    }
    catch(char* e)
    {
        cout << "char* e:" << e << endl;
    }
    catch(int e)
    {
        cout << "int e:" << e << endl;
    }
    finally:
    {
        cout << "finally" << endl;
    }
}

int main()
{
    testException2();
    return 0;
}
