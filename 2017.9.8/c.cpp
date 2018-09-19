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
#include<malloc.h>
#include<stack>
#define ll long long
#define read(a) scanf("%d",&a);
using namespace std;
typedef struct node{
	int sum;
	struct node *next[26];
}node;
char s[40];
char query[40];
struct node *root1=NULL,*root2=NULL;
void dfs(struct node *root){
	struct node *p=root;
	for(int i=0;i<26;i++){
		if(p->next[i]!=NULL){
			printf("%c",i+'a');
			dfs(p->next[i]);
		}
		else{
			printf("\n");
			return;
		}
	}
	return;
}
int main(){
	freopen("test.txt","r",stdin);
	int n;
	while(~scanf("%d",&n)){
		root1=NULL,root2=NULL;
		struct node *p;
		while(n--){
			scanf("%s",s);
			root1=(struct node *)malloc(sizeof(struct node));
			root1->sum=0;
			for(int i=0;i<26;i++){
				root1->next[i]=NULL;
			}
			p=root1;
			for(int i=0;i<strlen(s);i++){
				int num=s[i]-'a';
				if(p->next[num]==NULL){
					node *tmp=(node *)malloc(sizeof(node));
					printf("11111\n");
					tmp->sum=0;
					for(int j=0;j<26;j++){
						tmp->next[j]=NULL;
					}
					//p->sum++;
					p->next[num]=tmp;
					p=p->next[num];
					p->sum++;
				}
				else{
					//p->sum++;
					printf("2222\n");
					p=p->next[num];
					p->sum++;
				}
				printf("%c %d\n",s[i],p->sum);
			}
			puts(s);
			//dfs(root1);
			//printf("\n");
			// root2=(struct node *)malloc(sizeof(struct node));
			// root2->sum=0;
			// for(int i=0;i<26;i++){
			// 	root2->next[i]=NULL;
			// }
			// p=root2;
			// for(int i=strlen(s)-1;i>=0;i--){
			// 	int num=s[i]-'a';
			// 	if(p->next[num]==NULL){
			// 		struct node *tmp=(node *)malloc(sizeof(node));
			// 		tmp->sum=0;
			// 		for(int j=0;j<26;j++){
			// 			tmp->next[i]=NULL;
			// 		}
			// 		//p->sum++;
			// 		p->next[num]=tmp;
			// 		p=p->next[num];
			// 		p->sum++;
			// 	}
			// 	else{
			// 		//p->sum++;
			// 		p=p->next[num];
			// 		p->sum++;
			// 	}
			// 	//printf("%c %d\n",s[i],sum);
			// }
		}
		dfs(root1);
		int q;
		scanf("%d",&q);
		while(q--){
			scanf("%s",query);
			// int pos=0;
			// for(int i=0;i<strlen(query);i++){
			// 	if(query[i]=='*'){
			// 		pos=i;
			// 		break;
			// 	}
			// }
			// if(pos==0){
			// 	p=root2;
			// 	bool flag=false;
			// 	for(int j=strlen(query)-1;j>0;j--){
			// 		int num=query[j]-'a';
			// 		if(p->next[num]!=NULL){
			// 			p=p->next[num];
			// 		}
			// 		else{
			// 			flag=true;
			// 			break;
			// 		}
			// 	}
			// 	if(!flag){
			// 		printf("%d\n",p->sum);
			// 	}
			// 	else{
			// 		printf("-1\n");
			// 	}
			// }
			// else if(pos==strlen(query)-1){
			// 	p=root1;
			// 	bool flag=false;
			// 	for(int j=0;j<strlen(query)-1;j++){
			// 		int num=query[j]-'a';
			// 		if(p->next[num]!=NULL){
			// 			p=p->next[num];
			// 		}
			// 		else{
			// 			flag=true;
			// 			break;
			// 		}
			// 	}
			// 	if(!flag){
			// 		printf("%d\n",p->sum);
			// 	}
			// 	else{
			// 		printf("-1\n");
			// 	}
			// }
			// else{
			// 	;
			// }
		}
	}
	return 0;
}