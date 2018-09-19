#include<stdio.h>
int k,min=99999999;
void dfs(int step,int count,int t){
    int i;
    int acc=0;
    if(count==k){
        if(t<min)
            min=t;
        return;
    }
    for(i=0;i<2;i++){
        if(i==0){
            acc=count+step;
            if(t>k)
                continue;
            dfs(step+1,acc,t+1);
        }
        if(i==1){
            acc=count-step;
            if(t>k)
                continue;
            dfs(step+1,acc,t+1);
        }
    }
    return;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&k);
        if(k<0);
        k=-k;
        dfs(0,0,0);
        printf("%d\n",min-1);
    }
    return 0;
}
