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
bool is(int year){
    if(year%4==0&&year%100!=0)
        return true;
    else if(year%400==0)
        return true;
    else
        return false;
}
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int y,m,d;
        int s;
        char u,v;
        scanf("%d",&y);
        getchar();
        scanf("%d",&m);
        getchar();
        scanf("%d",&d);
        scanf("%d",&s);
        //printf("%d\n",s);
        //int a=86399;
        int day=s/86400;
        //printf("%d\n",day);
        if(s%86399!=0)
            day++;
        if(day>=1)
            day--;
        if(is(y))
            month[1]=29;
        else
            month[1]=28;
        int left=month[m-1]-d;
        if(left>=day){
            d+=day;
            //printf("%d\n",d);
        }
        else{
            day-=left;
            if(m<12)
                m++;
            else{
                m=1;
                y++;
                if(is(y))
                    month[1]=29;
                else
                    month[1]=28;
            }
            while(day!=0){
                if(month[m-1]<day){
                    day-=month[m-1];
                    if(m<12)
                        m++;
                    else{
                        m=1;
                        y++;
                        if(is(y))
                            month[1]=29;
                        else
                            month[1]=28;
                    }
                }
                else{
                    d=day;
                    day=0;
                }
                //printf("%d\n",day);
            }
        }
        printf("%d-",y);
        if(m<10)
            printf("0");
        printf("%d-",m);
        if(day<10)
            printf("0");
        printf("%d\n",day);
    }
    return 0;
}

