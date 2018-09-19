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
typedef struct tire_node{
    tire_node *next[27];
    bool flag;
    int id;
}tire;
int ance[500005],degree[500005];
int color;
char s1[20],s2[20];
void init(){

}
int insert(tire *root,char *s){
    tire *p=root;
    int i=0;
    while(s[i]!='\0'){
        if(p->next[s[i]-'a']==NULL){
            tire *tmp=new tire;
            for(int j=0;j<26;j++){
                tmp->next[j]=NULL;
            }
            tmp->id=0;
            tmp->flag=false;
            p->next[s[i]-'a']=tmp;
        }
        p=p->next[s[i]-'a'];
        i++;
    }
    if(p->flag){
        return p->id;
    }
    else{
        p->flag=true;
        p->id=color++;
        return p->id;
    }
}
int find(int a){
    if(ance[a]==-1) return a;
    else return ance[a]=find(ance[a]);
}
void union_set(int a,int b){
    int f1=find(a);
    int f2=find(b);
    if(f1!=f2)ance[f1]=f2;
}
int main(){
    tire *root=new tire;
    for(int i=0;i<26;i++){
        root->next[i]=NULL;
    }
    root->flag=false;
    root->id=0;
    color=0;
    memset(ance,-1,sizeof(ance));
    memset(degree,0,sizeof(degree));
    int f1,f2;
    int i,j,k;
    while(~scanf("%s %s",s1,s2)){
        f1=insert(root,s1);
        f2=insert(root,s2);
        degree[f1]++;
        degree[f2]++;
        union_set(f1,f2);
    }
    int coun1=0,coun2=0;
    bool fl=false;
    for(i=0;i<color;i++){
        if(ance[i]==-1)
            coun1++;
        if(degree[i]%2==1)
            coun2++;
        if(coun1>1)
            break;
        if(coun2>=3)
            break;
    }
    if((coun1==0||coun1==1)&&(coun2==0||coun2==2)){
        printf("Possible\n");
    }
    else
        printf("Impossible\n");
    return 0;
}

