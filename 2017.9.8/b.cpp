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
#define ll long long
#define read(a) scanf("%d",&a);
using namespace std;
int next[40];
char p[40];
char s[100005][40];
int st[100005];
char query[40];
int n;
void get_next(int len){
	next[0]=-1;
	int k=-1;
	int j=0;
	while (j < len - 1){  
        //p[k]表示前缀，p[j]表示后缀  
        if (k == -1 || p[j] == p[k])   {  
            ++k;  
            ++j;  
            next[j] = k;  
        }  
        else{  
            k = next[k];  
        }  
    }  
}
void print(int len){
	for(int i=0;i<len;i++){
		printf("%c",p[i]);
	}
	printf("\n");
}
int kmp_search(int cur,int plen,int start){
	int i=start,j=0;
	int slen=strlen(s[cur]);
	while (i < slen && j < plen)  
    {  
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
        if (j == -1 || s[cur][i] == p[j])  
        {  
            i++;  
            j++;  
        }  
        else  
        {  
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = next[j]      
            //next[j]即为j所对应的next值        
            j = next[j];  
        }  
    }  
    if (j == plen)  
        return i;  
    else  
        return -1; 
}
int main(){
	freopen("test.txt","r",stdin);
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%s",s[i]);
		}
		int q;
		scanf("%d",&q);
		while(q--){
			scanf("%s",query);
			int pos=0;
			for(int i=0;i<strlen(query);i++){
				if(query[i]=='*'){
					pos=i;
				}
			}
			int num=0;
			int ans=0;
			ans=0;
			if(pos==0){
				printf("case 1: ");
				for(int i=1;i<strlen(query);i++){
					p[num]=query[i];
					num++;
				}
				get_next(num);
				// printf("%d \n",num);
				print(num);
				for(int i=0;i<n;i++){
					int tmp=kmp_search(i,num,0);
					if(tmp!=-1){
						ans++;
					}
					printf("%d %d %d\n",i,tmp,ans);
				}
				printf("%d\n",ans);
			}
			else if(pos==strlen(query)-1){
				printf("case 2: ");
				for(int i=0;i<pos;i++){
					p[i]=query[i];
				}
				get_next(pos);
				// printf("%d\n",pos);
				print(pos);
				for(int i=0;i<n;i++){
					int tmp=kmp_search(i,pos,0);
					if(tmp!=-1){
						ans++;
					}
					printf("%d %d %d\n",i,tmp,ans);
				}
				printf("%d\n",ans);
			}
			else{
				printf("case 3: ");
				for(int i=0;i<pos;i++){
					p[i]=query[i];
				}
				get_next(pos);
				// printf("%d\n",pos);
				print(pos);
				for(int i=0;i<n;i++){
					st[i]=kmp_search(i,pos,0);
				}
				num=0;
				for(int i=pos+1;i<strlen(query);i++){
					p[num]=query[i];
					num++;
				}
				get_next(num);
				// printf("%d\n",num);
				print(num);
				for(int i=0;i<n;i++){
					if(st[i]!=-1){
						int tmp=kmp_search(i,pos,st[i]+1);
						if(tmp!=-1){
							ans++;
						}
						printf("%d %d %d\n",i,tmp,ans);
					}
				}
				printf("%d\n",ans);
			}
		}
	}
	return 0;
}