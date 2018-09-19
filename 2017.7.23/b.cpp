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
using namespace std;
struct matrix{
	int m[2][2];
};
matrix operator * (matrix,matrix);
matrix operator *= (matrix,matrix);
matrix operator ^ (matrix,matrix);
matrix operator ^ (matrix a,int b){
	matrix ans;
	int i,j;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			ans.m[i][j]=(i==j);
		}
	}
	if(b&1)
		ans*=a;
	b>>=1;
	a*=a;
	return ans;
}
matrix operator *= (matrix a,matrix b){
	return a=a*b;
}
matrix operator * (matrix a,matrix b){
	matrix ans;
	int i,j,k;
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			for(k=0;k<2;k++){
				ans.m[i][j]+=(a.m[i][k]%10000)*(b.m[k][j]%10000);
				ans.m[i][j]%=10000;
			}
		}
	}
	return ans;
}
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	matrix a;
	a.m[0][0]=1;a.m[0][1]=1;a.m[1][0]=1;a.m[1][1]=0;
	int b;
	while(~scanf("%d",&b)&&b!=-1){
		matrix ans;
		ans=a^b;
		printf("%d\n",ans.m[1][1]);
	}
	return 0;
}