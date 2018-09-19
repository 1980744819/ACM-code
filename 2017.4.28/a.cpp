#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	int a[100][100];
	int i,j,k;
	int tmp;
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			a[i][j]=rand()%1000;
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			for(k=0;k<j;k++){
				if(a[i][k]<a[i][j]){
					tmp=a[i][k];
					a[i][k]=a[i][j];
					a[i][j]=tmp;
				}
			}
		}
	}
	printf("\n");
	for(i=0;i<20;i++){
		for(j=0;j<20;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}