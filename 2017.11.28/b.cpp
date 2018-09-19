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
#define ll long long
using namespace std;
const int maxn=10000;
int getgcd(int x,int y){
         return (x==0)?y:getgcd(y%x,x);
}
int main(){
	//freopen("test.txt","r",stdin);
	//freopen("test.out","w",stdout);
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d %d\n",getgcd(a,b),a*b/getgcd(a,b));
    return 0;
}

