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
    multiset<int>st;
    multiset<int>::iterator it;
    int a;
    char c;
    int tmp,tm;
    int i,j;
    int t;
    scanf("%d",&t);
    int cd,d;
    bool flag;
    int coun;
    while(t--){
        getchar();
        scanf("%c %d",&c,&a);
        //printf("%c %d\n",c,a);
        if(c=='+'){
            st.insert(a);
        }
        else if(c=='-'){
            it=st.find(a);
            if(it!=st.end()){
                st.erase(it);
            }
        }
        else if(c=='?'){
            coun=0;
            for(it=st.begin();it!=st.end();it++){
                tmp=*it;
                tm=a;
                flag=false;
                while(tmp!=0&&tm!=0){
                    cd=tmp%10;
                    d=tm%10;
                    if(d==0){
                        if(cd%2!=0){
                            flag=true;
                            break;
                        }
                    }
                    else{
                        if(cd%2==0){
                            flag=true;
                            break;
                        }
                    }
                    tmp/=10;
                    tm/=10;
                }
                if(flag==false){
                    if(tmp!=0){
                        while(tmp!=0){
                            cd=tmp%10;
                            if(cd%2!=0){
                                flag=true;
                                break;
                            }
                            tmp/=10;
                        }
                    }
                    else if(tm!=0){
                        while(tm!=0){
                            d=tm%10;
                            if(d%2!=0){
                                flag=true;
                                break;
                            }
                            tm/=10;
                        }
                    }
                }
                if(flag==false){
                    coun++;
                }
            }
            printf("%d\n",coun);
        }
    }
    return 0;
}

