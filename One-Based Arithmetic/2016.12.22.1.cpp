#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
struct stu{
    int num;
    int id;
}a[100];
bool cmp(stu u,stu v){
    return u.num>v.num;
}
int main(){
    int n;
    while(~scanf("%d",&n)){
        for(i=0;i<n;i++){
            scanf("%d",&a[i].num);
            a[i].id=i;
        }
        //sort(a,a+n,cmp);
        for(i=0;i<n;i++){
            for(j=0;j<i;j++){
                int tmp,tmp_id;
                if(a[i].num>a[j].num){
                    tmp=a[i].num;
                    tmp_id=a[i].id;
                    a[i].num=a[j].num;
                    a[i].id=a[j].id;
                    a[j].num=tmp;
                    a[j].id=tmp_id;
                }
            }
        }
        for(i=0;i<n;i++){
            printf("%d %d\n",a[i].num,a[i].id);
        }
    }
    return 0;
}

