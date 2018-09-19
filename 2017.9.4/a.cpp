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
int main(){
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	//printf("%d\n",t);
	while(t--){
		int n;
		int a[maxn];
		scanf("%d",&n);
		queue<int>que,tmp;
		while(!que.empty())
			que.pop();
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			que.push(a[i]);
		}
		int temp;
		int gre,le;
		gre=0;
		le=0;
		int flag=0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				temp=que.front();
				que.pop();
			 	que.push(temp);
				if(j!=i){
					tmp.push(temp);
				}
			}
			temp=tmp.front();
			tmp.pop();
			gre=0;
			le=0;
			while(!tmp.empty()){
				int num=tmp.front();
				tmp.pop();
				if(num>temp){
					gre++;
				}
				else if(num<temp){
					le++;
				}
				else{
					gre++;
					le++;
				}
				temp=num;
			}
			//printf("%d %d\n",gre,le);
			if(gre==n-2||le==n-2){
				printf("YES\n");
				flag=1;
				break;
			}
		}
		if(flag==0){
			printf("NO\n");
		}
	}
    return 0;
}
