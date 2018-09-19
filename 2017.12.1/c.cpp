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
#define ll long long
using namespace std;
const int maxn=10000;
int num;
double f_x(int n){
	if(n==0)
		return cos(num);
	else
		return cos(f_x(n-1));
}
int main(){
	//freopen("test.txt","r",stdin);
	//freopen("test.out","w",stdout);
	// int n;
	while(~scanf("%d",&num)){
		for(int i=1;i<=num;i++){
			printf("%d: %.6f\n",i,f_x(i));
		}
	}
    return 0;
}
