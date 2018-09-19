#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int mon[13];
int s,d;
int add(int i,int j){
    int ans=0;
    for(i=i;i<=j;i++){
        if(mon[i]==1){
            ans+=s;
        }
        else{
            ans-=d;
        }
    }
    return ans;
}
int main(){
    int i,j;
    while(~scanf("%d%d",&s,&d)){
        for(i=1;i<=12;i++){
            mon[i]=1;
        }
        for(i=1;i<=8;i++){
                j=i+4;
            while(add(i,i+4)>0){
                mon[j]=0;
                j--;
            }
        }
        int ans=add(1,12);
        if(ans>=0)
            printf("%d\n",ans);
        else
            printf("Deficit\n");
    }
    return 0;
}

