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
int get_sum(int i){
	int res=i;
	while(i){
		int num=i%10;
		res+=num;
		i/=10;
	}
	return res;
}
int main(){
	freopen("test.txt","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		std::vector<int> v;
		v.clear();
		for(int i=max(n-100,1);i<n;i++){
			if(get_sum(i)==n){
				v.push_back(i);
			}
		}
		printf("%d\n",v.size());
		for(int i=0;i<v.size();i++){
			printf("%d%c",v[i],i==v.size()-1?'\n':' ');
		}
	}
    return 0;
}
