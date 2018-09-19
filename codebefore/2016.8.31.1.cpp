#include<iostream>
using namespace::std;
#include<cstdio>
inline bool isnumber(char ch){
    return((ch>='0')&&(ch<='9'));
}
int main(){
    char c;
    while((c=cin.get())!='q'){
        if(isnumber(c)){
            cout<<"you enter a digit"<<endl;
        }
        else{
            cout<<"you enter a non-digit"<<endl;
        }
    }
    return 0;
}
