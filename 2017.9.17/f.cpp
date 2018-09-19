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
int main(){
	freopen("test.txt","w",stdout);
	int num=5;
	int a,b;
	a=1;
	while(num--){
		for(int i=0;i<rand()%10;i++){
			printf("%d ",a++);
		}
		for(int i=0;i<rand()%10;i++){
			if(a>=1)
				printf("%d ",a--);
		}
	}
    return 0;
}
