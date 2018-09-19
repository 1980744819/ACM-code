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
bool judge(int a,int b,int c,int d){
	if(a==d&&b==c){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	int hh,mm;
	int i,j,k;
	int num;
	int a,b,c,d;
	char ch;
	while(~scanf("%d%c%d",&hh,&ch,&mm)){
		//printf("%d %d\n",hh,mm);
		a=hh/10;
		b=hh%10;
		c=mm/10;
		d=mm%10;
		num=0;
		while(!judge(a,b,c,d)){
			num++;
			mm++;
			if(mm>=60){
				mm-=60;
				hh++;
				if(hh>=24){
					hh-=24;
				}
			}
			a=hh/10;
			b=hh%10;
			c=mm/10;
			d=mm%10;
		}
		printf("%d\n",num);
	}
    return 0;
}
