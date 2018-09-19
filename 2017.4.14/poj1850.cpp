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
int mx[27][27];
void init(){
	int i,j;
	for(i=0;i<=26;i++){
		for(j=0;j<=i;j++){
			if(j==0||i==j){
				mx[i][j]=1;
			}
			else{
				mx[i][j]=mx[i-1][j-1]+mx[i-1][j];
			}
			//printf("%d ",mx[i][j]);
		}
		//printf("\n");
	}
}
int main(){
	char s[15];
	init();
	int len,i,j;
	int sum;
	char ch;
	bool flag;
	while(~scanf("%s",s)){
		len=strlen(s);
		flag=false;
		for(i=1;i<len;i++){
			if(s[i]<=s[i-1]){
				printf("0\n");
				flag=true;
				break;
			}
		}
		if(flag)
			continue;
		sum=0;
		for(i=0;i<len;i++){
			sum+=mx[26][i];
		}
		for(i=0;i<len;i++){
			i==0?ch='a':ch=s[i-1]+1;
			while(ch<s[i]){
				sum+=mx['z'-ch][len-i-1];
				ch++;
			}
		}
		printf("%d\n",sum);
	}
    return 0;
}
