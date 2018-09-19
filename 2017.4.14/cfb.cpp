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
int main(){
	int n;
	int num;
	int i,j;
	int ma,mb,mc;
	ma=99999999;
	mb=99999999;
	int sum=0;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&num);
		if(num>0){
			sum+=num;
			if(num%2==1&&num<ma){
				ma=num;
			}
		}
		else if(num<0){
			num=0-num;
			if(num%2==1&&num<mb){
				mb=num;
			}
		}
	}
	if(sum%2==0){
		sum-ma>sum-mb?sum-=ma:sum-=mb;
	}
	printf("%d\n",sum);
    return 0;
}
