/*
 *  STL bitset
 *
 *  bit集合，可用来实现bitmap
 */

 #include <iostream>
 #include <bitset>
 using namespace std;

 int main()
 {
     bitset<32> b;

     cout<<"size:"<<b.size()<<endl;

    b[1]=1;
     for(int i=0;i<32;i++){
        cout<<"b["<<i<<"]="<<b[i]<<endl;
     }

     return 0;
 }


