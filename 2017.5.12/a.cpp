#include<stdio.h>
#include<math.h>
int solve(int num){
	if(num==1)
		return 1;
	else return n*solve(num-1);
}
int mian(){
	int i,j;
	int ans=0;
	for(i=1;i<=5;i++){
		sum+=solve(i);
	}
	printf("%d\n",sum);
	return 0;
}