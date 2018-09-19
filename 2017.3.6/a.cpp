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
int score[100005];
int n;
int solve(){
    int ans=1;
    int i;
    for(i=1;i<=n;i++){
        if(score[i]==2&&score[i-1]==1)
            ans++;
        else if(score[i-1]==2&&score[i]==1)
            ans++;
        else if(score[i]-score[i-1]>3||score[i-1]-score[i]>3)
            return 0;
        else if(score[i]==score[i-1]&&score[i]!=1);
            return 0;
    }
    if(score[n]!=0)
        ans*=2;
    return ans;
}
int main(){
    int t;
    int i,j;
    int kase=1;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=1;i<=n;i++){
            scanf("%d",&score[i]);
        }
        cout<<"Case #"<<kase++<<": ";
        //int ans=solve();
        int ans=1;
        for(i=1;i<=n;i++){
            if(score[i]==2&&score[i-1]==1)
                ans++;
            else if(score[i-1]==2&&score[i]==1)
                ans++;
            else if(score[i]-score[i-1]>3||score[i-1]-score[i]>3){ans=0;break;}
                //return 0;
            else if(score[i]==score[i-1]&&score[i]!=1){ans=0;break;}
                //return 0;
        }
        if(score[n])
            ans*=2;
        cout<<ans<<endl;
    }
    return 0;
}


