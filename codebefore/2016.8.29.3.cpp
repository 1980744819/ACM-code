#include<iostream>
using namespace::std;
void foo(int val){
    val=10;
}
void bar(int& val){
    val=10;
}
void zoo(int* val){
    *val=10;
}
int main(){
    int a,b,c;
    a=b=c=1;
    foo(a);
    bar(b);
    zoo(&c);
    cout<<a<<endl<<b<<endl<<c<<endl;
    return 0;
}
