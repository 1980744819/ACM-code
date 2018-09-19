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
int dp[105];
struct stu {
	int len,wid,hei;
};
bool cmp(struct stu u,struct stu v){
	return u.len>v.len;
}
int main(){
	//freopen("test.txt","r",stdin);
	int m,n;
	int i,j;
	int a,b,c;
	struct stu tmp;
	std::vector<struct stu> vec;
	int kase=0;
	while(~scanf("%d",&n)&&n){
		kase++;
		vec.clear();
		for(i=0;i<n;i++){
			scanf("%d %d %d",&a,&b,&c);
			tmp.len=a;//1
			tmp.wid=b;
			tmp.hei=c;
			vec.push_back(tmp);
			tmp.len=a;//2
			tmp.wid=c;
			tmp.hei=b;
			vec.push_back(tmp);
			tmp.len=b;//3
			tmp.wid=a;
			tmp.hei=c;
			vec.push_back(tmp);
			tmp.len=b;//4
			tmp.wid=c;
			tmp.hei=a;
			vec.push_back(tmp);
			tmp.len=c;//5
			tmp.wid=a;
			tmp.hei=b;
			vec.push_back(tmp);
			tmp.len=c;//6
			tmp.wid=b;
			tmp.hei=a;
			vec.push_back(tmp);
		}
		sort(vec.begin(),vec.end(),cmp);
		// for(i=0;i<vec.size();i++){
		// 	printf("%d %d %d\n",vec[i].len,vec[i].wid,vec[i].hei);
		// }
		for(i=0;i<vec.size();i++){
			dp[i]=vec[i].hei;
		}
		int Max=0;
		for(i=1;i<vec.size();i++){
			for(j=0;j<i;j++){
				if(vec[i].len<vec[j].len&&vec[i].wid<vec[j].wid&&dp[i]<dp[j]+vec[i].hei){
					dp[i]=dp[j]+vec[i].hei;
					if(Max<dp[i])
						Max=dp[i];
				}
			}
		}
		printf("Case %d: maximum height = %d\n",kase,Max);
	}
	return 0;
}