#include<iostream>
//#include<stdio.h>
using namespace::std;
int squre(int x){
    cout<<_FILE_<<_LINE_<<_func_<<endl;
    return x*x;
}
float squre(float x){
    cout<<_FILE_<<_LINE_<<_func_<<endl;
    return x*x;
}
double squre(double x){
    cout<<_FILE_<<_LINE_<<_func_<<endl;
    return x*x;
}
int main(){
    cout<<"squre(10)    "<<squre(10)<<endl;
    cout<<"suqure(2.5f)     "<<squre(2.5f)<<endl;
    cout<<"squre(1.1)       "<<squre(1.1)<<endl;
    return 0;
}
