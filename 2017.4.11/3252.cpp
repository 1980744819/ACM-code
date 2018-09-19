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
//#include<windows.h>
using namespace std;
int main(){
	long long num;
	long long s,f;
	std::vector<long long> v;
	num=2;
	int i,j;
	i=1;
	long long coun;
	while(i<=15){
		coun=1;
		for(j=2*i-1;j>=i;j--){
			coun*=j;
		}
		for(j=i;j>1;j--){
			coun/=j;
		}
		v.push_back(coun);
		printf("%d %d\n",i,coun);
		i++;
		num=1<<(2*i);
		//printf(" %d %lld\n",i,num);
		//Sleep(500);
	}
	for(i=0;i<v.size();i++){
		printf("%d\n",v[i]);
	}
	int ans;
	while(~scanf("%lld %lld",&s,&f)){
		i=1;
		coun=0;
		ans=0;
		while(1<<(2*i)<s&&i<=15){
			i++;
		}
		while(1<<(2*i)<=f&&i<=15){
			coun=1;
			for(j=2*i-1;j>=i;j--){
				coun*=j;
			}
			for(j=i;j>1;j--){
				coun/=j;
			}
			ans+=coun;
			i++;
		}
		printf("%d\n",ans);
	}
    return 0;
}
