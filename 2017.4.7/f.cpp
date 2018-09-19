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
char c[100005];
int b[400005];
int d[100005];
int main(){
    int n;
    int i,j;
    int lenc,lenb,lend;
    int tmp,tm;
    int res;
    scanf("%d",&n);
        while(n--){
            scanf("%s",c);
            //puts(c);
            lenc=strlen(c);
            //printf("%d\n",lenc);
            lenb=0;
            for(i=0;i<lenc;i++){
                if(c[i]>='0'&&c[i]<='9'){
                    tmp=c[i]-'0';
                }
                else{
                    tmp=c[i]-'A'+10;
                }
                //printf("%d\n",tmp);
                //tmp=4;
                for(j=0;j<4;j++){
                    tm=tmp%2;
                    //printf("%d\n",tm);
                    tmp>>=1;
                    b[lenb*4+3-j]=tm;
                }
                lenb++;
            }
            lenb=4*lenc;
            /*for(i=0;i<lenb;i++){
                printf("%d",b[i]);
            }
            printf("\n");*/
            res=lenb%3;
            tm=0;
            for(i=0;i<res;i++){
                tmp=pow(2,res-i-1)*b[i];
                tm+=tmp;
            }
            d[0]=tm;
            lend=1;
            for(i=res;i<lenb;i+=3){
                tm=4*b[i]+2*b[i+1]+b[i+2];
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
