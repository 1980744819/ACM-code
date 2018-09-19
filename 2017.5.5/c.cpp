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
double fun(int n){
	if(n==1)
		return 1;
	else
		return n*fun(n-1);
}
double sum(int n){
	int i,j;
	double su=1;
	double ans;
	for(i=1;i<=10;i++){
		ans=1/fun(i);
		if(i%2==0){
			su-=ans;
		}
		else{
			su+=ans;
		}
	}
	return su;
}
int main(){
	int i,j;
	int n;
	printf("%f\n",sum(10));
    return 0;
}
