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
const int maxn=1006;
int p[maxn];
bool book[maxn];
int inf=99999999;
struct node{
	int id,num;
	bool operator <(node a)
	{
		return this->num<a.num;
	}
};
bool cmp(node a,node b){
	return a.num<b.num;
}
int main(){
	freopen("test.txt","r",stdin);
	int n,m;
	while(~scanf("%d %d",&n,&m)){
		memset(p,0,sizeof(p));
		memset(book,false,sizeof(book));
		for(int i=0;i<n;i++){
			scanf("%d",&p[i]);
		}
		int q;
		scanf("%d",&q);
		for(int i=0;i<q;i++){
			int num;
			scanf("%d",&num);
			//printf("%d\n",p[i]);
			book[num]=true;
		}
		vector<int>v;
		v.clear();
		for(int i=0;i<n;i++){
			if(!book[i])
				v.push_back(i);
		}
		for(int i=0;i<v.size();i++){
			printf("%d %d\n",v[i],p[v[i]]);
		}
		printf("\n");
		int ans=inf;
		int a=0,b=1;
		for(int i=0;i<=v.size()-m;i++){
			//priority_queue<node>q1;
			//priority_queue<int,vector<int>,less<int>>q2;
			vector<node>vec;
			vec.clear();
			for(int j=0;j<m;j++){
				struct node t;
				t.id=i+j;
				t.num=p[i+j];
				//vec[j]=t;
				//q2.push(p[i+j]);
				vec.push_back(t);
			}

			sort(vec.begin(), vec.begin()+m,cmp);
			// while(!q1.empty()){
			// 	printf("%d ",q1.top().num);
			// 	q1.pop();
			// }
			// printf("\n");
			for(int j=0;j<m;j++){
				printf("%d ",vec[j].num);
			}
			printf("\n");
			node tmp1,tmp2;
			tmp1=vec[0];
			//q1.pop();
			tmp2=vec[1];
			if(ans>tmp1.num+tmp2.num){
				ans=tmp1.num+tmp2.num;
				a=tmp1.id;
				b=tmp2.id;
			}
		}
		printf("%d %d %d\n\n",ans,a,b);
	}
    return 0;
}
