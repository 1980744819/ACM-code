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

int main(){
    int t;
    int i,j;
    int kase=1;
    int n;
    cin>>t;
    while(t--){
        cin>>n;
        for(i=0;i<n;i++){
            scanf("%d",&score[i]);
        }
        cout<<"Case #"<<kase++<<": ";
        sort(score,score+n);
        /*for(i=0;i<n;i++){
            cout<<score[i]<<endl;
        }*/
        int ans=0;
        i=n-1;
        int p=n-1;
        while(i--){
            if(score[i]<score[p]){
                ans+=score[i];
                score[p]-=score[i];
            }
            else{
                ans+=score[p];
                score[i]-=score[p];
                p=i;
            }
            //cout<<p<<" ";
        }
        cout<<ans+score[p]<<endl;
    }
    return 0;
}

