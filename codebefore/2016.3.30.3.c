#include<stdio.h>
#include<string.h>

int a[100000],b[100000];

int main(){
    int i,j;
    int m,n;
    while(~scanf("%d",&m)){
        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
        for(i=0;i<m;i++){
            scanf("%d",&a[i]);
        }
        scanf("%d",&n);
        for(i=0;i<n;i++){
            scanf("%d",&b[i]);
        }
        for(i=0;i<m-1;i++){
            printf("%d ",a[i]);
        }
        printf("%d\n",a[m-1]);
        for(i=0;i<n-1;i++){
            printf("%d ",b[i]);
        }
        printf("%d\n",b[n-1]);
        int flag;
        int ans=0;
        for(i=0;i<n;i++){
                flag=1;
                for(j=0;j<m+ans;j++){
                    if(b[i]==a[j]){
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                    ans++;
                    a[m-1+ans]=b[i];
                }
            for(j=0;j<m-1+ans;j++){
                printf("%d ",a[j]);
            }
            printf("%d\n",a[m-1+ans]);
        }
        printf("\n");
    }
    return 0;
}
