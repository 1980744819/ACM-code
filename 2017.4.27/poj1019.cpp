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
long long a[32000],b[32000];//第i组的长度，到第i组的长度
char c[320000];
int main(){
	int i,j;
	int t,num;
	a[0]=0;
	a[1]=1;
	b[0]=0;
	b[1]=1;
	for(i=2;i<32000;i++){
		a[i]=(int)log10(1.0*i)+1+a[i-1];
		b[i]=b[i-1]+a[i];
		//printf("%d %d\n",i,b[i]);
	}
	int len;
	int tmp;
	int ti=1;
	char s[20];
	for(i=1;i<31300;i++){
		len=0;
		num=i;
		while(num!=0){
			tmp=num%10;
			s[len]=tmp+'0';
			len++;
			num/=10;
		}
		//printf("%d\n",len);
		len--;
		while(len>=0){
			c[ti]=s[len];
			len--;
			ti++;
		}
	}
	// for(i=0;i<ti;i++){
	// 	printf("%c",c[i]);
	// }
	// printf("\n");
	scanf("%d",&t);
	while(t--){
		scanf("%d",&num);
		i=1;
		while(b[i]<num)
			i++;
		num-=b[i-1];
		printf("%c\n",c[num]);
	}
    return 0;
}
