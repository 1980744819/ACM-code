#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int d[400005];
int main(){
    int n;
    int i,j;
    int lenc;
    long long num;
    int tmp;
    string a,b;
    int lena,lenb,lend;
    cin>>n;
    int res;
    int tm;
    while(n--){
        cin>>a;
        b="";
        for(i=0;i<a.size();i++){
            switch(a[i]){
                case '0':b+="0000";break;
                case '1':b+="0001";break;
                case '2':b+="0010";break;
                case '3':b+="0011";break;
                case '4':b+="0100";break;
                case '5':b+="0101";break;
                case '6':b+="0110";break;
                case '7':b+="0111";break;
                case '8':b+="1000";break;
                case '9':b+="1001";break;
                case 'A':b+="1010";break;
                case 'B':b+="1011";break;
                case 'C':b+="1100";break;
                case 'D':b+="1101";break;
                case 'E':b+="1110";break;
                case 'F':b+="1111";break;
                default:break;
            }
        }
        //printf("1\n");
        res=b.size()%3;
        tm=0;
        for(i=0;i<res;i++){
            tmp=pow(2,res-i-1)*(b[i]-'0');
            tm+=tmp;
        }
        d[0]=tm;
        lend=1;
        for(i=res;i<b.size();i+=3){
            tm=4*(b[i]-'0')+2*(b[i+1]-'0')+b[i+2]-'0';
            d[lend]=tm;
            lend++;
        }
        i=0;
        while(d[i]==0){
            i++;
        }
        for(;i<lend;i++){
            printf("%d",d[i]);
        }
        printf("\n");
    }
    return 0;
}

