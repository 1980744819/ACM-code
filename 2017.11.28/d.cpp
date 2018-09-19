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
#include<windows.h>
#define ll long long
using namespace std;
const int maxn=10000;
bool judge(int num){
	//printf("")
	while(num!=0){
		int tmp=num%10;
		num/=10;
		if(tmp!=5||tmp!=0){
			return false;
		}
	}
	return true;
}
int main(){
	// freopen("test.txt","r",stdin);
	// freopen("test.out","w",stdout);
	int maxnum=1<<30;
	for(int num=90;num<=maxnum;num+=90){
		//printf("%d\n",num);
		if(judge(num))
			printf("%d\n",num);
		//Sleep(200);
	}
    return 0;
}
