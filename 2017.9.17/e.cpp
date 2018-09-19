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
#include<time.h>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=100005;
string st1[maxn];
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
void insert(int pos){
	node *p=root;
	for(int i=0;i<st1[pos].size();i++){
		int x=st1[pos][i]-'a';
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
void ac_automation(int pos){
	node *p=root;
	int len=st1[pos].size();
	for(int i=0;i<len;i++){
		int x=st1[pos][i]-'a';
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
	//scanf("%d",&t);
	cin>>t;
	while(t--){
		root=(struct node *)malloc(sizeof(struct node));
        for(int j=0;j<26;j++) root->next[j] = 0;
        root->fail = 0;
        root->sum = 0;
		//scanf("%d",&n);
		cin>>n;
		maxlen=0;
		maxlen_pos=0;
		for(int i=0;i<n;i++){
			cin>>st1[i];
			int len=st1[i].size();
			if(len>maxlen){
				maxlen=st1[i].size();
				maxlen_pos=i;
			}
		}
		for(int i=0;i<n;i++){
			if(i!=maxlen_pos)
				insert(i);
		}
		cnt = 0;
        build_fail_pointer();
        ac_automation(maxlen_pos);
        if(cnt==n-1){
        	cout<<st1[maxlen_pos]<<endl;
        }
        else{
        	cout<<"No"<<endl;
        }
        del(root);
	}
    end=clock();
    printf("%d\n",end-begin);
   	return 0;
}
