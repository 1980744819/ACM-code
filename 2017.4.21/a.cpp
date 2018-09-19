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
int ball[5005],coun[5005],col[5005];
int main(){
	int i,j;
	int cal=0;
	int n;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&ball[i]);
	}
	int len;
	int tmp;
	int max=0;
	for(i=1;i<=n;i++){
		max=0;
		col[ball[i]]++;
		coun[ball[i]]++;
		if(max<coun[ball[i]]){
			max=coun[ball[i]];
			tmp=ball[i];
		}
		for(j=i+1;j<=n;j++){
			coun[ball[j]]++;
			if(max<coun[ball[j]]){
				max=coun[ball[j]];
				tmp=ball[j];
			}
			else if(max==coun[ball[j]]){
				if(tmp>ball[j]){
					tmp=ball[j];
				}
			}
			col[tmp]++;
		}
		memset(coun,0,sizeof(coun));
	}
	for(i=1;i<=n;i++){
		printf("%d",col[i]);
		if(i!=n)
			printf(" ");
	}
	printf("\n");
    return 0;
}
