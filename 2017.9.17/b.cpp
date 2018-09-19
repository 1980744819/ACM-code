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
#include<time.h>
#define ll long long
using namespace std;
const int maxn=100005;
//string st1[maxn];
char s[maxn];
char tmp[maxn];
int n;
int maxlen,maxlen_pos;
struct node{
    node *next[26];
    node *fail;
    int sum;
};
int head,tail;
node *root;
node *q[maxn];
node *newnode;
int cnt;
void insert(int len){
	node *p=root;
	for(int i=0;i<len;i++){
		int x=tmp[i]-'a';
		if(p->next[x]==NULL){
			newnode=(struct node *)malloc(sizeof(struct node));
            for(int j=0;j<26;j++) newnode->next[j] = 0;
            newnode->sum = 0;newnode->fail = 0;
            p->next[x]=newnode;
		}
		p = p->next[x];
	}
	p->sum++;
}
void insert1(int len){
	node *p=root;
	for(int i=0;i<len;i++){
		int x=s[i]-'a';
		if(p->next[x]==NULL){
			newnode=(struct node *)malloc(sizeof(struct node));
            for(int j=0;j<26;j++) newnode->next[j] = 0;
            newnode->sum = 0;newnode->fail = 0;
            p->next[x]=newnode;
		}
		p = p->next[x];
	}
	p->sum++;
}
void build_fail_pointer(){
    head = 0;
    tail = 1;
    q[head] = root;
    node *p;
    node *temp;
    while(head < tail)
    {
        temp = q[head++];
        for(int i = 0; i <= 25; i++)
        {
            if(temp->next[i])
            {
                if(temp == root)
                {
                    temp->next[i]->fail = root;
                }
                else
                {
                    p = temp->fail;
                    while(p)
                    {
                        if(p->next[i])
                        {
                            temp->next[i]->fail = p->next[i];
                            break;
                        }
                        p = p->fail;
                    }
                    if(p == NULL) temp->next[i]->fail = root;
                }
                q[tail++] = temp->next[i];
            }
        }
    }
}
void ac_automation(int len){
	node *p=root;
	//int len=st1[pos].size();
	for(int i=0;i<len;i++){
		int x=tmp[i]-'a';
        while(!p->next[x] && p != root) p = p->fail;
        p = p->next[x];
        if(!p) p = root;
        node *temp = p;
        while(temp != root)
        {
           if(temp->sum >= 0)
           {
               cnt += temp->sum;
               temp->sum = -1;
           }
           else break;
           temp = temp->fail;
        }
        // if(cnt==n-1)
        // 	return;
	}
}
void del(node *head)                      //释放整个字典树占的堆区空间    
{   
    int i;   
    for(i=0;i<26;i++)   
    {   
        if(head->next[i]!=NULL)   
        {   
            del(head->next[i]);   
        }   
    }   
    free(head);   
}

int main(){
	int begin,end;
	begin=clock();
	freopen("test.txt","r",stdin);
	//std::ios::sync_with_stdio(false);
	int t;
	scanf("%d",&t);
	//cin>>t;
	while(t--){
		root=(struct node *)malloc(sizeof(struct node));
        for(int j=0;j<26;j++) root->next[j] = 0;
        root->fail = 0;
        root->sum = 0;
		scanf("%d",&n);
		//cin>>n;
		maxlen=0;
		//maxlen_pos=0;
		//tmp[0]='\0';
		scanf("%s",s);
		int ln=strlen(s);
		for(int i=0;i<ln;i++)
			tmp[i]=s[i];
		tmp[ln]='\0';
		//insert(strlen(s));
		for(int i=1;i<n;i++){
			//cin>>st1[i];
			scanf("%s",s);
			int len=strlen(s);
			if(len>maxlen){
				insert(strlen(tmp));
				maxlen=len;
				//maxlen_pos=i;
				for(int j=0;j<len;j++){
					tmp[j]=s[j];
				}
				tmp[len]='\0';
			}
			else{
				insert1(len);
			}
		}
		// for(int i=0;i<n;i++){
		// 	if(i!=maxlen_pos)
		// 		insert(i);
		// }
		cnt = 0;
        build_fail_pointer();
        ac_automation(maxlen);
        if(cnt==n-1){
        	//cout<<st1[maxlen_pos]<<endl;
        	printf("%s\n",tmp);
        }
        else{
        	//cout<<"No"<<endl;
        	printf("No\n");
        }
        del(root);
        for(int i=0;i<maxlen;i++){
        	tmp[i]='\0';
        }
	}
	end=clock();
	//cout<<end-begin<<endl;
	printf("%d\n",end-begin);
   	return 0;
}
