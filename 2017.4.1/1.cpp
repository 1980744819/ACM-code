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
int main(){
    set<int>st;
    int n;
    int t;
    scanf("%d",&t);
    int i,j;
    int ans;
    int num;
    while(t--){
        scanf("%d",&n);
        ans=1;
        for(i=0;i<n;i++){
            scanf("%d",&num);
            if(st.find(num)==st.end()){
                st.insert(num);
            }
            else{
                ans++;
            }
        }
        printf("%d\n",ans);
        st.clear();
    }
    return 0;
}

