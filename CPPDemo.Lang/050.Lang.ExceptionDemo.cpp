/*
*   Exception
*
*
*/

#include <iostream>
using namespace std;

// 该函数可能抛异常并带有声明
void methodMayException() throw (char *,int)
{
    throw 1;
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
        methodMayException();
    }
    catch(char * e)
    {
        cout << e << endl;
    }
    catch(int e)
    {
        cout << e << endl;
    }
    finally:
        {
            cout << "finally" << endl;
        }
}



int main_4()
{
    testException2();

    return 0;
}
