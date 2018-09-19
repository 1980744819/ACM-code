#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<string>
using namespace std;
int main(){
    int time;
    int kase;
    scanf("%d",&kase);
    time=0;
    while(kase--){
        char a[105];
        char b[105];
        char s[210];
        int c;
        time++;
        scanf("%d",&c);
        memset(a,'\0',sizeof(a));
        memset(b,'\0',sizeof(b));
        memset(s,'\0',sizeof(s));
        scanf("%s",a);
        scanf("%s",b);
        scanf("%s",s);
        map<string,bool>vis;
        vis[s]=true;
        int step;
        step=0;
        int i;
        while(true){
            char tmp[210];
            int ptmp=0;
            for(i=0;i<c;i++){
                tmp[ptmp]=b[i];
                ptmp++;
                tmp[ptmp]=a[i];
                ptmp++;
            }
            tmp[ptmp]='\0';
            step++;
            if(strcmp(s,tmp)==0){
                printf("%d %d\n",time,step);
                break;
            }
            else if(vis[tmp]&&strcmp(s,tmp)!=0){
                printf("%d -1\n",time);
                break;
            }
            vis[tmp]=true;
            for(i=0;i<c;i++){
                a[i]=tmp[i];
            }
            a[i]='\0';
            int k;
            for(k=0;i<2*c;k++,i++){
                b[k]=tmp[i];
            }
            b[k]='\0';
        }
    }
    return 0;
}
