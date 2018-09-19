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
    struct tire_node *next[128];
    bool flag;
    int id;
}tire;
int coun;
int sp;
int num[10005];
int create(tire *root,char *s){
    int i=0;
    int index=0;
    tire *p=root;
    while(s[i]!='\0'){
        index=s[i];
        if(p->next[index]==NULL){
            //printf("%c",s[i]);
            tire *tmp=new tire;
            for(int j=0;j<=127;j++){
                tmp->next[j]=NULL;
            }
            tmp->id=0;
            tmp->flag=false;
            p->next[index]=tmp;
        }
        //printf("%c",index);
        p=p->next[index];
        i++;
    }
    if(p->flag){
        return p->id;
    }
    else{
        p->flag=true;
        p->id=sp++;
        return p->id;
    }
}
char str[35];
void dfs(tire *root,int k){
    tire *p=root;
    if(p->flag==true){
        //printf("%c",str[0]-32);
        for(int i=0;i<k;i++){
            printf("%c",str[i]);
        }
        printf(" ");
        double ans;
        ans=num[p->id]*1.0;
        ans/=coun*1.0;
        printf("%.4lf\n",ans*100);
        return;
    }
    else{
        for(int i=0;i<=127;i++){
            if(p->next[i]!=NULL){
                str[k]=i;
                dfs(p->next[i],k+1);
            }
        }
    }
}
int main(){
    char s[35];
    int i,j,k;
    tire *root=new tire;
    for(i=0;i<=127;i++){
        root->next[i]=NULL;
    }
    root->flag=false;
    root->id=0;
    coun=0;
    sp=0;
    double ans;
    while(gets(s)){
        //puts(s);
        coun++;
        k=create(root,s);
        //printf("%d\n",k);
        num[k]++;
    }
    dfs(root,0);
    return 0;
}

