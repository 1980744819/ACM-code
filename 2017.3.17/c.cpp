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
struct stu{
    char name[20];
    bool sex;
    bool vi;
}stu[55];
int main(){
    int n;
    int i,j;
    int m,w;
    int s;
    int coun;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            scanf("%d",&s);
            if(s==0){
                stu[i].sex=false;
            }
            else{
                stu[i].sex=true;
            }
            getchar();
            scanf("%s",stu[i].name);
            //printf("%s",stu[i].name);
            stu[i].vi=false;
        }
        coun=0;
        i=0;
        while(i<n){
            printf("%s",stu[i].name);
            stu[i].vi=true;
            printf(" ");
            j=n-1;
            while(j>i){
                if(!stu[j].vi&&stu[j].sex!=stu[i].sex){
                    printf("%s\n",stu[j].name);
                    stu[j].vi=true;
                    break;
                }
                j--;
            }
            coun++;
            if(coun==n/2)
                break;
            i++;
        }
    }
    return 0;
}
