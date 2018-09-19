#include<iostream>
using namespace::std;
//void foo(int i,int j=5,int k=10);
void foo(int i,int j=5,int k=10){
    cout<<i<<endl<<j<<endl<<k<<endl;
}
int main(){
    foo(20);
    cout<<endl;
    foo(20,30);
    cout<<endl;
    foo(20,30,40);
    cout<<endl;
    return 0;
}

