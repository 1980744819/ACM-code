#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
#define OK 1
#define ERROR 0
typedef struct glnode{
    int tag;
    union{
        char atom;
        struct glnode *hp;
    }atom_hp;
    struct glnode *tp;
}glnode,*glist;
glnode *glcreat(char *s){
    glnode *p,*q,*r,*head;
    char substr[200],hstr[200];
    int len=strlen(s);
    if(strcmp(s,"()")==0||len==0)
        head=NULL;
    else if(len==1){
        head=(glnode *)malloc(sizeof(glnode));
        if(head==NULL)
            return NULL;
        head->tag=0;
        head->atom_hp.atom=*s;
        head->atom_hp.hp=NULL;
    }
    else{
        head=(glnode *)malloc(sizeof(glnode));
        if(head==NULL)
            return NULL;
        head->tag=1;
        p=head;
        s++;
        strncpy(substr,s,len-2);//°þÀëÍâ²ãµÄÀ¨ºÅ
        substr[len-2]='\0';
        while(len>0){
            disastr(substr,hstr);
            r=glcreat(hstr);
            p->atom_hp.hp=r;
            q=p;
            len=strlen(substr);
            if(len>0){
                p=(glnode *)malloc(sizeof(glnode));
                if(p==0)
                    return NULL;
                p->tag=1;
                q->tp=p;
            }
        }
        q->tp=NULL;
    }
    return head;
}
void disastr(char *s,char *hstr){
    int i,j,k,r;
    char rstr[200];
    i=j=k=0;
    while(s[i]&&(s[i]!=','||k)){
        if(s[i]=='(')
            k++;
        else if(s[i]==')')
            k--;
        if(s[i]!=','||s[i]==','&&k){
            hstr[j]=s[i];
            i++;
            j++;
        }
    }
    hstr[j]='\0';
    if(s[i]==',')
        i++;
    r=0;
    while(s[i]){
        rstr[r]=s[i];
        r++;
        i++;
    }
    rstr[r]='\0';
    strcpy(s,rstr);
}
int depth(glist l){
    int d,max;
    glnode *s;
    if(l==NULL) return 1;
    if(l->tag==0) return 0;
    s=l;
    max=0;
    while(s){
        d=depth(s->atom_hp.hp);
        if(d>max) max=d;
        s=s->tp;
    }
    return max+1;
}
int main(){
    char s[200],a[200];
    glist head;
    glist l;
    scanf("%s",s);
    head=glcreat(s);
    printf("%d\n",depth(head));
    return 0;
}

