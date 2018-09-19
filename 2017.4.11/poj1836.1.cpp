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
double st1[1005],st2[1005];
int binary(double num,int top,double s[]){
	int low,heigh;
	int mid;
	low=0;
	heigh=top;
	while(low<=heigh){
		mid=(low+heigh)/2;
		if(s[mid]<num){
			low=mid+1;
		}
		else{
			heigh=mid-1;
		}
	}
	return low;
}
int main(){
	int dph[1005],dpl[1005];
	int top1,top2;
	double he[1005];
	int n;
	int ans;
	int i,j;
	int pos;
	while(~scanf("%d",&n)){
		for(i=0;i<n;i++){
			scanf("%lf",&he[i]);
		}
		top1=0;
		top2=0;
		st1[top1]=he[0];
		dph[0]=1;
		for(i=1;i<n;i++){
			if(st1[top1]<he[i]){
				top1++;
				st1[top1]=he[i];
			}
			else{
				pos=binary(he[i],top1,st1);
				st1[pos]=he[i];
			}
			dph[i]=top1+1;
		}
		st2[top2]=he[n-1];
		dpl[n-1]=1;
		for(i=n-2;i>=0;i--){
			if(he[i]>st2[top2]){
				top2++;
				st2[top2]=he[i];
			}
			else{
				pos=binary(he[i],top2,st2);
				st2[pos]=he[i];
			}
			dpl[i]=top2+1;
		}
		ans=0;
		for(i=0;i<n-1;i++){
			for(j=i+1;j<n;j++){
				ans=max(ans,(dph[i]+dpl[j]));
			}
		}
		printf("%d\n",n-ans);
	}
    return 0;
}
