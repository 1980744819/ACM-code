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
int soc[100005];
int main(){
    int i,j,k;
    int ans;
    int coun;
    int n;
    int a;
    while(cin>>n){
        ans=0;
        coun=0;
        for(i=1;i<=2*n;i++){
           cin>>a;
           if(soc[a]==0){
               coun++;
               soc[a]++;
               if(ans<coun)
                ans=coun;
           }
           else{
               soc[a]--;
               coun--;
           }
        }
        cout<<ans<<endl;
        memset(soc,0,sizeof(soc));
    }
    return 0;
}

