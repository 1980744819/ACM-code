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
char s[55][55];
char tm[55];
char plan[55];
int len;
void rev(char c[]){
	int i;
	char tmp;
	tmp=c[0];
	for(i=0;i<len-1;i++){
		c[i]=c[i+1];
	}
	c[len-1]=tmp;
}
int main(){
	int n;
	int i,j,k,u,v;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%s",s[i]);
		//puts(s[i]);
	}
	len=strlen(s[1]);
	//printf("%d\n",len);
	char tmp;
	int coun=0;
	int MIN=999999999;
	strcpy(plan,s[1]);
	bool flag;
	for(i=0;i<len;i++){
		coun=0;
		//puts(plan);
		for(j=1;j<=n;j++){
			strcpy(tm,s[j]);
			flag=false;
			for(k=0;k<len;k++){
				//printf("%d %d",j,k);
				//puts(tm);
				if(strcmp(plan,tm)==0){
					flag=true;
					coun+=k;
					break;
				}
				rev(tm);
			}
			if(flag==false){
				printf("-1\n");
				return 0;
			}
		}
		if(MIN>coun)
			MIN=coun;
		rev(plan);
	}
	printf("%d\n",MIN);
    return 0;
}
