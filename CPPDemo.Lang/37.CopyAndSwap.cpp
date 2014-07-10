/*
 *  TODO Copy and Swap 习语
 *
 *  why?
 *      在自己实现拷贝赋值操作符的时候（自己分配内存、赋值、释放旧资源），有一些问题，比如假若分配内存过程中出现了异常，那么旧对象的状态发生了改变。且代码十分臃肿。
 *      通过std::swap来自定义一个swap()，可避免上述问题。
 *
 *  how?
 *
 *
 *  @see http://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
 */

#include <iostream>
using namespace std;

class Class33
{
    int age;

public:
    Class33()
    {
        cout << "ctor" << endl;
    }

    Class33(const Class33& that)
    {
        age=that.age;
    }

/*
    Class33& operator = (const Class33& that) // copy-assignment operator，使用引用做参数
    {
        cout << "operator = ref" << endl;
        if(this==&that)
        {
            return *this;
        }
        age=that.age;
        return *this;
    }
*/

    Class33& operator = (Class33 that)// copy-assignment operator，使用值传递参数
    {
        cout << "operator = value" << endl;
        std::swap(*this,that);
        return *this;
    }
};

int main37()
{
    Class33 c1;
    Class33 c2;

    c2 = c1 ; //
}
