/*
 *  [TODO] Rule of Three
 *
 */

 #include <iostream>
 #include <cstring>
 #include <stdio.h> // C IO

 class Person
 {
 public:
     char * name;
     int age;
     int * pInt;
 public:
    Person(const char* name,int age);
    //Person(const Person& _p);
    ~Person();
 };

// ʹ�� C Style �ַ���ʵ�ֹ��캯��
Person::Person(const char * p_name,int age)
{
    name = new char[strlen(p_name)+1];
    strcpy(name,p_name);
    this->age = age;
}

// �������캯��
/*
Person::Person(const Person& _p)
{
    std::cout << "copy ctor" << std::endl;
    name=_p.name;
    age=_p.age;
}
*/

// ��������
Person::~Person()
{
    delete[] name;
}


int main666()
{
    Person p1("name1",1);
    Person p2(p1);

    p1.name="changed";
    *(p1.pInt)=1;

    printf("%p\r\n",p1.pInt);
    printf("%p\r\n",p2.pInt);

    std::cout << *(p1.pInt) << "," << p2.pInt << std::endl;
}
