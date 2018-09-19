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
int a[8];
int main(){
	freopen("test.txt","r",stdin);
	int num;
	while(~scanf("%d",&num)){
		printf("%d\n",num);
		memset(a,0,sizeof(a));
		if(num<0){
			a[0]=1;
			num=0-num;
		}
		int pos=7;
		while(num){
			if(num%2){
				a[pos]=1;
			}
			else{
				a[pos]=0;
			}
			num/=2;
			pos--;
		}
		for(int i=0;i<8;i++){
			printf("%d",a[i]);
		}
		printf("\n");
		if(a[0]){
			for(int i=1;i<8;i++){
				if(a[i]==1)
					a[i]=0;
				else
					a[i]=1;
			}
		}
		for(int i=0;i<8;i++){
			printf("%d",a[i]);
		}
		printf("\n");
		if(a[0]){
			pos=7;
			a[pos]+=1;
			while(a[pos]>1){
				a[pos]-=2;
				pos++;
			}
		}
		for(int i=0;i<8;i++){
			printf("%d",a[i]);
		}
		printf("\n");

	}
    return 0;
}
