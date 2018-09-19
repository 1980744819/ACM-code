#include<iostream>
using namespace::std;
int main(){
    int intone=0;
    int& r_int_one=intone;
    intone=5;
    cout<<intone<<endl;
    cout<<r_int_one<<endl;

    r_int_one=7;

    cout<<intone<<endl;
    cout<<r_int_one<<endl;

    cout<<&(intone)<<endl;
    cout<<&(r_int_one)<<endl;
    return 0;
}
