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
bool is[200005];
int main(){
    int r_coun,d_coun;
    int n;
    int d;
    int r;
    char c[200005];
    int i;
    while(~scanf("%d",&n)){
        r_coun=0;
        d_coun=0;
        d=0;
        r=0;
        getchar();
        for(i=0;i<n;i++){
            scanf("%c",&c[i]);
            if(c[i]=='D')
                d++;
            else r++;
        }
        while(r!=0&&d!=0){
            d_coun=0;
            r_coun=0;
            for(i=0;i<n;i++){
                if(is[i]==false){
                    if(c[i]=='D'){
                        d_coun++;
                        if(r_coun>0){
                            r_coun--;
                            d_coun--;
                            d--;
                            is[i]=true;
                        }
                        else{
                            if(r>0){
                                r--;
                                is[]
                            }
                        }
                    }
                    else{
                        r_coun++;
                        if(d_coun>0){
                            r_coun--;
                            d_coun--;
                            r--;
                            is[i]=true;
                        }
                    }
                }
                if(r==0||d==0)
                    break;
            }
            for(i=0;i<n;i++){
                if(is[i]==false)
                    printf("%c",c[i]);
                else
                printf(" ");
            }
            printf("\n");
            if(r==0||d==0)
                break;
        }
        if(r!=0)
            printf("R\n");
        else
            printf("D\n");
        memset(is,false,sizeof(is));
    }
    return 0;
}

