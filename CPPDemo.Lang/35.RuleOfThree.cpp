/*
 *  [TODO] Rule of Three
 *
 */

 #include <iostream>
 #include <cstring>
 #include <stdio.h>

 class Person
 {
 private:
    int age;
public:
    Person()
    {

    }

    Person(const Person& _person) // 1
    {

    }

    Person& operator = (const Person& _person) // 2
    {
        if(this==&_person)
        {
            return *this;
        }
        age=_person.age;
        return *this;
    }

    ~Person() // 3
    {
        // delete
    }
 };


int main35()
{

    return 0;
}
