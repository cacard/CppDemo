/*
 *  string
 *
 */

#include <iostream>

void testString()
{
    std::string str0("abc"); // ֱ�ӳ�ʼ��
    std::string str1 = "abc"; // ������ʼ��

    // ��������
    for(int i=0;i<str0.length();i++)
    {
        std::cout << str0[i] << std::endl;
    }

    // ����������
    for(std::string::iterator iter = str0.begin();iter!=str0.end();iter++)
    {
        std::cout << *iter << std::endl;
    }

    // for ���� (C++ 11)
    /*
    for(std::string s : str0) // auto s& ��ʹ���������ͣ����ֱ���޸��ַ�����
    {
    }
    */


}



int main8()
{
    testString();
    return 0;
}
