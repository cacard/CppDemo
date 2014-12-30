/*
 *  C++ string demo
 */

#include <iostream>

void testString()
{
    std::string str0("abc"); // 直接初始化
    std::string str1 = "abc"; // 拷贝初始化

    // 索引迭代
    for(int i=0; i<str0.length(); i++)
    {
        std::cout << str0[i] << std::endl;
    }

    // 迭代器迭代
    for(std::string::iterator iter = str0.begin(); iter!=str0.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }

    // for 迭代 (C++ 11)
    for(auto s : str0) // auto s& 若使用引用类型，则可直接修改字符串。
    {
        std::cout << s << std::endl;
    }

}

int main()
{
    testString();
    return 0;
}
