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
// #include<windows.h>
#define ll long long
using namespace std;
const int maxn=1000006;
int prime[maxn];
void getprime(){
	int n=2;
	while(n<maxn){
		int num=n*2;
		while(num<maxn){
			prime[num]=-1;
			num+=n;
		}
		num=n+1;
		while(prime[num]==-1&&num<maxn){
			num++;
		}
		n=num;
	}
}
int main(){
	getprime();
	vector<int>pri;
	int coun=0;
	for(int i=2;i<maxn;i++){
		if(prime[i]==0){
			pri.push_back(i);
			// printf("%d ",i);
			prime[i]=coun;
			coun++;
		}
	}
	// printf("%d\n",pri[pri.size()-1]);
	// for(int i=2;i<=100;i++){
	// 	printf("%d %d\n",i,prime[i]);
	// }
	// printf("%d\n",pri.size());
	int x2;
	int x1;
	int x0;
	while(~scanf("%d",&x2)){
		x0 = 9999999;
		int num = x2;
		// praintf("%d=",num);
		// int coun=0;
		// vector<int>div;
		int b=0;
		for(int i=0;i<pri.size()&&num!=1;i++){
			while(num%pri[i]==0){
				num/=pri[i];
				b=max(b,pri[i]);
				// if(coun==0){
				// 	printf("%d", pri[i]);
				// 	div.push_back(pri[i]);
				// }
				// else{
				// 	printf("*%d", pri[i]);
				// 	if(div[coun-1]!=pri[i]){
				// 		div.push_back(pri[i]);
				// 	}
				// }
				// coun++;
			}
		}
		// printf("\n");
		int a=0;
		for(int i=x2-b+1;i<=x2;i++){
			for(int j=0;pri[j]<i;j++){
				if(i%pri[j]==0){
					a=max(a,pri[j]);
				}
			}
			x0=min(i-a+1,x0);
		}
		printf("%d\n",x0);
	}
    return 0;
}
