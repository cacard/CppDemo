/*
 *  MyResource�ඨ��ͷ�ļ�
 *
 */


#ifndef MYRESOURCE_H_INCLUDED
#define MYRESOURCE_H_INCLUDED
#endif // MYRESOURCE_H_INCLUDED

class MyResource
{
private:
    size_t len;
    int* data;
public:
        MyResource();
        MyResource(int len);
        MyResource(const MyResource& other);
};
