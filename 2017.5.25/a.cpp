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
char a[105],b[205],c[105];
int d[105];
int solve(int a,int b,char c){
	int ans;
	if(c=='+'){
		ans=a+b;
	}
	else if(c=='-'){
		ans=a-b;
	}
	else if(c=='*'){
		ans=a*b;
	}
	else if(c=='/'){
		ans=a/b;
	}
	return ans;
}
int priority(char c){
	if(c=='('||c==')'){
		return 1;
	}
	else if(c=='+'||c=='-'){
		return 2;
	}
	else if(c=='*'||c=='/'){
		return 3;
	}
}
int main(){
	int i,j;
	scanf("%s",a);
	int topb,topc,topd;
	topb=-1;topc=-1;topd=-1;
	for(i=0;a[i]!='\0';i++){
		if(a[i]>='0'&&a[i]<='9'){
			topb++;
			b[topb]=a[i];
			if(a[i+1]=='+'||a[i+1]=='-'||a[i+1]=='*'||a[i+1]=='/'||a[i+1]=='('||a[i+1]==')'||a[i+1]=='\0'){
				topb++;
				b[topb]='#';
			}
		}
		else if(a[i]==')'){
			while(c[topc]!='('){
				topb++;
				b[topb]=c[topc];
				topc--;
			}
			topc--;
		}
		else{
			int tmp=priority(a[i]);
			if(tmp!=1){
				while(topc>=0&&priority(c[topc])>=tmp&&c[topc]!='('){
					topb++;
					b[topb]=c[topc];
					topc--;
				}
			}
			topc++;
			c[topc]=a[i];
		}
	}
	while(topc>=0){
		topb++;
		b[topb]=c[topc];
		topc--;
	}
	//puts(b);
	int num=0;
	for(i=0;i<=topb;i++){
		if(b[i]>='0'&&b[i]<='9'){
			//printf("1\n");
			num*=10;
			num+=b[i]-'0';
			if(b[i+1]=='#'){
				topd++;
				d[topd]=num;
				num=0;
			}
		}
		else if(b[i]=='#'){
			//printf("2\n");
			num=0;
		}
		else{
			//printf("3\n");
			int tmb=d[topd];
			topd--;
			int tma=d[topd];
			d[topd]=solve(tma,tmb,b[i]);
		}
	}
	printf("%d\n",d[topd]);
    return 0;
}
