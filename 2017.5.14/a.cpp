#include<stdio.h>
int kmp(){
	int i,j;
	return 0;
}
int main()
{
    int c[100][100];
    int n,i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            if(j==0||j==i){
                c[i][j]=1;
            }
            else{
                c[i][j]=c[i-1][j-1]+c[i-1][j];
            }
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
