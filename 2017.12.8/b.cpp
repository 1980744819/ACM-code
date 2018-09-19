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
const int maxn=100005;
char s[maxn],p[maxn];
char str[maxn];
int Next[maxn];
void GetNextval()  
{  
    int pLen = strlen(p);  
    Next[0] = -1;  
    int k = -1;  
    int j = 0;  
    while (j < pLen - 1)  
    {  
        //p[k]表示前缀，p[j]表示后缀    
        if (k == -1 || p[j] == p[k])  
        {  
            ++j;  
            ++k;  
            //较之前Next数组求法，改动在下面4行  
            if (p[j] != p[k])  
                Next[j] = k;   //之前只有这一行  
            else  
                //因为不能出现p[j] = p[ Next[j ]]，所以当出现时需要继续递归，k = Next[k] = Next[Next[k]]  
                Next[j] = Next[k];  
        }  
        else  
        {  
            k = Next[k];  
        }  
    }  
} 
int KmpSearch()  
{  
    int i = 0;  
    int j = 0;  
    int sLen = strlen(s);  
    int pLen = strlen(p); 
    int ans=0; 
    while (i < sLen && j < pLen)  
    {  
        //①如果j = -1，或者当前字符匹配成功（即S[i] == P[j]），都令i++，j++      
        if (j == -1 || s[i] == p[j])  
        {  
            i++;  
            j++;  
        }  
        else  
        {  
            //②如果j != -1，且当前字符匹配失败（即S[i] != P[j]），则令 i 不变，j = Next[j]      
            //Next[j]即为j所对应的Next值        
            j = Next[j];  
        }
        if(j==pLen){
        	i=i-j+1;
        	j=0;
        	ans++;
        }  
    }  
    return ans;
}  
int main(){
	freopen("test.txt","r",stdin);
	//freopen("test.out","w",stdout);
	while(~scanf("%s",str)){
		int q;
		scanf("%d",&q);
		while(q--){
			int l,r;
			memset(p,'\0',sizeof(p));
			memset(s,'\0',sizeof(s));
			scanf("%d %d %s",&l,&r,p);
			for(int i=l;i<=r;i++)
				s[i-l]=str[i];
			GetNextval();
			int ans;
			ans=KmpSearch();
			printf("%d\n",ans);
		}
	}
    return 0;
}
