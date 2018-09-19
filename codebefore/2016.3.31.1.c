#include<stdio.h>
#include<string.h>
int a[100000];
int main(){
    int i,j;
    int m,n;
    while(~scanf("%d",&m)){
        for(i=0;i<m;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&a[m+i]);
        }
        for(i=1;i<m+n;i++){
            for(j=0;j<i;j++){
                if(a[i]<a[j]){
                    int an=a[i];
                    a[i]=a[j];
                    a[j]=an;
                }
            }
        }
        for(i=0;i<n+m-1;i++){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[m+n-1]);
        memset(a,'\0',sizeof(a));
    }
    return 0;
}
