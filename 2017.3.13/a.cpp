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
    int i,j;
    int n;
    multiset<int>s;
    multiset<int>::iterator p;
    while(~scanf("%d",&n)){
        s.clear();
        int op;
        int num;
        while(n--){
            scanf("%d",&op);
            if(op==1){
                scanf("%d",&num);
                s.insert(num);
            }
            else if(op==2){
                if(!s.empty()){
                    p=s.begin();
                    s.erase(p);
                }
            }
            else if(op==3){
                if(s.empty())
                    printf("0\n");
                else{
                    p=s.end();
                    p--;
                    printf("%d\n",*p);
                }

            }
        }
    }
    return 0;
}

