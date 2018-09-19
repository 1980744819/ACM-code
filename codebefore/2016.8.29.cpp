#include<iostream>
using namespace::std;
namespace one{
    int m=200;
    int inf=10;
}
namespace two{
    int x;
    int inf=100;
}
int main(){
    using two::x;
    cout<<x<<endl;
    x-=100;
    one::inf*=1;
    cout<<one::inf<<endl;
    cout<<one::m<<endl;
    two::inf*=2;
    cout<<two::inf<<endl;
    cout<<x<<endl;
    return 0;
}
