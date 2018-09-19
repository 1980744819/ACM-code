#include<stdio.h>
#include<string.h>
int a[1005],b[1005]={0};
int main(){
    int n,m;
    int i,j;
    int an;
    scanf("%d",&n);
    while(n--){
            an=0;
        scanf("%d",&m);
        for(i=0;i<m;i++){
            scanf("%d",&a[i]);
        }
        b[0]=0;
        for(i=1;i<m;i++){
            for(j=0;j<i;j++){
                if(a[i]<a[j])
                    b[i]++;
            }
        }
        for(i=1;i<m;i++)
            an+=b[i];
        printf("%d\n",an);
        memset(a,'\0',sizeof(a));
        memset(b,0,sizeof(b));
    }
    return 0;
}
