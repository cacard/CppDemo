//
//  当主线程异常时，如何保证子线程的可join
//
//  RAII dtor
//

#include <iostream>
#include <thread>

// #2:在类的析构函数中join子线程

int main()
{

    thread t(NULL);

    // #1:using try catch
    try{
        // some operation
    }catch(Exception e){
        if(t.joinable()){
            t.join();
        }
    }



    return 0;
}
