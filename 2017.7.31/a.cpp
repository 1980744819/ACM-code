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
const int maxn=1e7+5;
int cnt;
struct node{
	node *next[26];
	node *fail;
	int sum;
};
node *root;
char key[70];
node *q[maxn];
int head,tail;
node *newnode;
char pattern[maxn];
int N;
void Insert(char *s){
	node *p=root;
	for(int i=0;s[i]!='\0';i++){
		int x=s[i]-'a';
		if(p->next[x]==NULL){
			newnode=(struct node *)malloc(sizeof(struct node));
			for(int j=0;j<26;j++){
				newnode->next[j]=0;
			}
			newnode->fail=0;
			newnode->sum=0;
			p->next[x]=newnode;
		}
		p=p->next[x];
	}
	p->sum++;
}
void build_fail_pointer(){
	head=0;
	tail=1;
	q[head]=root;
	node *p;
	node *temp;
	while(head<tail){
		temp=q[head];
		head++;
		for(int i=0;i<26;i++){
			if(temp->next[i]){
				if(temp==root){
					temp->next[i]->fail=root;
				}
				else{
					p=temp->fail;
					while(p){
						if(p->next[i]){
							temp->next[i]->fail=p->next[i];
							break;
						}
						p=p->fail;
					}
					if(p==NULL)temp->next[i]->fail=root;
				}
				q[tail]=temp->next[i];
				tail++;
			}
		}
	}
}
void ac_automation(char *ch){
	node *p=root;
	int len=strlen(ch);
	for(int i=0;i<len;i++){
		int x=ch[i]-'a';
		while(!p->next[x]&&p!=root)p=p->fail;
		p=p->next[x];
		if(!p)p=root;
		node *temp=p;
		while(temp!=root){
			if(temp->sum>=0){
				cnt+=temp->sum;
				temp->sum=-1;
			}
			else
				break;
			temp=temp->fail;
		}
	}
}
int main(){
	freopen("test.txt","r",stdin);
	int i,j;
	int t;
	scanf("%d",&t);
	while(t--){
		root=(struct node *)malloc(sizeof(struct node));
		for(i=0;i<26;i++){
			root->next[i]=0;
		}
		root->sum=0;
		root->fail=0;
		scanf("%d",&N);
		//getchar();
		while(N--){
			scanf("%s",key);
			Insert(key);
		}
		scanf("%s",pattern);
		cnt=0;
		build_fail_pointer();
		ac_automation(pattern);
		printf("%d\n",cnt);
	}
	return 0;
}