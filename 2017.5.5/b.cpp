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
bool is(int num){
	int a,b,c;
	a=num/100;
	b=num%100/10;
	c=num%10;
	if(a*a*a+b*b*b+c*c*c==num){
		return true;
	}
	else
		return false;
}
int main(){
	int i,j;
	int sum=0;
	for(i=100;i<=999;i++){
		if(is(i)){
			printf("%d ",i);
			sum+=i;
		}
	}
	printf("\n");
	printf("%d\n",sum);
	while(sum){
		printf("%d ",sum%10);
		sum/=10;
	}
	printf("\n");
    return 0;
}
