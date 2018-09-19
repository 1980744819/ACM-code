#include<cstdio>
#include<string>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#define ll long long
#define read(a) scanf("%d",&a);
using namespace std;
double sq[100010];
void init(){
	int i,j;
	sq[0]=0;
	sq[1]=0;
	sq[2]=0;
	sq[3]=0.5;
	i=1;
	int num=4;
	double b=0.5;
	while(num<=90000){
		int tmp=i*i*2;
		b=i-0.5;
		sq[num]=tmp;
		sq[num+1]=tmp+b;
		sq[num+2]=tmp+i*2;
		sq[num+3]=tmp+i*3+0.5;
		i++;
		num=i*4;
	}
	// for(int i=1;i<=100;i++){
	// 	printf("%d : %lf\n",i,sq[i]);
	// 	// if(sq[i]<sq[i-1]){
	// 	//  	printf("%d %lf %lf\n",i,sq[i-1],sq[i]);
	// 	// 	break;
	// 	// }
	// }
}
int main(){
	freopen("test.txt","r",stdin);
	init();
	int t;
	scanf("%d",&t);
	while(t--){
		double size;
		scanf("%lf",&size);
		int ans=lower_bound(sq,sq+90000,size)-sq;
		printf("%d\n",ans);
	}
	return 0;
}