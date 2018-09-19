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
int c[35][35];
int b[35];
void init(){
	int i,j;
	for(i=0;i<35;i++){
		for(j=0;j<=i;j++){
			if(j==0||i==j){
				c[i][j]=1;
			}
			else{
				c[i][j]=c[i-1][j-1]+c[i-1][j];
			}
			//printf("%d ",c[i][j]);
		}
		//printf("\n");
	}
}
void change_to(int num){
	b[0]=0;
	int i,j;
	i=1;
	int tmp;
	while(num){
		b[i]=num%2;
		b[0]++;
		num/=2;
		i++;
	}
}
int cal_rou(int num){
	change_to(num);
	int i,j;
	int sum=0;
	for(i=1;i<b[0]-1;i++){
		for(j=i/2+1;j<=i;j++){
			sum+=c[i][j];
		}
	}
	int zero;
	zero=0;
	for(i=b[0]-1;i>=1;i--){
		if(b[i]){
			for(j=(b[0]+1)/2-(zero+1);j<i;j++){
				sum+=c[i-1][j];
			}
		}
		else{
			zero++;
		}
	}
	return sum;
}
int main(){
	int i,j;
	int s,f;
	init();
	int sum;
	while(~scanf("%d %d",&s,&f)){
		sum=cal_rou(f+1)-cal_rou(s);
		printf("%d\n",sum);
	}
    return 0;
}
