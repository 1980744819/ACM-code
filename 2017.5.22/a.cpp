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
struct stu{
	char ch;
	int sum;
}node[26];
char s[200005];
void sorted(){
	int i,j;
	int tmp;
	char tm;
	for(i=0;i<26;i++){
		for(j=0;j<i;j++){
			if(node[i].sum>node[j].sum){
				tmp=node[i].sum;
				tm=node[i].ch;
				node[i].sum=node[j].sum;
				node[i].ch=node[j].ch;
				node[j].sum=tmp;
				node[j].ch=tm;
			}
		}
	}
}
bool cmp(stu a,stu b){
	if(a.sum!=b.sum){
		return a.sum>b.sum;
	}
	else{
		return a.ch<b.ch;
	}
}
int main(){
	int i,j;
	int ans;
	int len;
	int l,r;
	int tmp;
	for(i=0;i<26;i++){
		node[i].ch='a'+i;
		node[i].sum=0;
	}
	scanf("%s",s+1);
	len=strlen(s+1);
	for(i=1;i<len+1;i++){
		tmp=s[i]-'a';
		node[tmp].sum++;
	}
	sort(node,node+26,cmp);
	//sorted();
	// for(i=0;i<26;i++){
	// 	printf("%c %d\n",node[i].ch,node[i].sum);
	// }
	i=0;
	l=1;r=len;
	while(l<r&&node[i].sum>=2){
		while(node[i].sum>=2&&l<r){
			s[l]=node[i].ch;
			s[r]=node[i].ch;
			node[i].sum-=2;
			//printf("%d %d %d\n",i,l,r);
			//puts(s);
			//node[i].sum-=1;
			l++;
			r--;
		}
		//printf("%d\n",i);
		i++;
	}
	sort(node,node+26,cmp);
	//sorted();
	i=0;
	while(l<=r&&node[i].sum>0){
		while(node[i].sum>0&&l<=r){
			s[l]=s[r]=node[i].ch;
			node[i].sum-=2;
			l++;
			r--;
		}
		i++;
	}
	sort(s+1,s+len/2+1);
	for(i=1;i<=len/2;i++)
		printf("%c",s[i]);
	if(len%2==1)
		printf("%c",s[len/2+1]);
	for(i=len/2;i>=1;i--){
		printf("%c",s[i]);
	}
	printf("\n");
	//puts(s+1);
    return 0;
}
