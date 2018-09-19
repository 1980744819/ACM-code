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
char s[19];
int a[19]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char M[11]={'1','0','X','9','8','7','6','5','4','3','2'};
int main(){
    int n;
    int i;
    bool flag;
    int coun;
    int z;
    int sum;
    int t;
    while(~scanf("%d",&n)){
        coun=0;
        t=n;
        while(n--){
            scanf("%s",s);
            flag=false;
            for(i=0;i<17;i++){
                if(s[i]>'9'||s[i]<'0'){
                    flag=true;
                    break;
                }
            }
            if(!flag){
                sum=0;
                for(i=0;i<17;i++){
                    sum+=a[i]*(s[i]-'0');
                }
                sum%=11;
                if(M[sum]!=s[17]){
                    flag=true;
                }
            }
            if(flag){
                puts(s);
            }
            else{
                coun++;
                //printf("%d\n",coun);
            }
        }
        if(coun==t){
            printf("All passed\n");
        }
        //printf("%d\n",coun);
    }
    return 0;
}
