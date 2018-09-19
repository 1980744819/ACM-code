#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
struct stu{
    string name;
    int value;
}stu[105];
bool cmp(struct stu a,struct stu b){
    return a.value>b.value;
}
int main(){
    char s[15],c[15];
    int i,j;
    map<string,int>map_s;
    int kase;
    int n;
    scanf("%d",&kase);
    int ans;
    while(kase--){
        scanf("%d",&n);
        for(i=0;i<n;i++){
            cin>>stu[i].name>>stu[i].value;
        }
        ans=0;
        sort(stu,stu+n,cmp);
        for(i=0;i<n;i++){
            if(!map_s[stu[i].name]){
                map_s.insert(stu[i].name,1);
                ans+=stu[i].value;
            }
            else{
                if(map_s[stu[i].name]<2){
                    map_s[stu[i].name]++;
                    ans+=stu[i].value;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
