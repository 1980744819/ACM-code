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
int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
bool is(int year){
    if(year%4==0&&year%100!=0)
        return true;
    else if(year%400==0)
        return true;
    else
        return false;
}
int main(){
    int t;
    int year,mon,day,sec;
    int left_time;
    int i,j,k;
    char c1,c2;
    int d;
    scanf("%d",&t);
    while(t--){
        scanf("%d%c%d%c%d %d",&year,&c1,&mon,&c2,&day,&sec);
        if(is(year))
            month[1]=29;
        else
            month[1]=28;
        d=sec/86400;
        left_time=month[mon-1]-day;
        if(left_time>=d){
            day+=d;
            d=0;
            left_time=0;
        }
        else{
            day=0;
            d-=left_time;
            if(mon<12)
                mon++;
            else{
                mon=1;
                year++;
                if(is(year))
                    month[1]=29;
                else
                    month[1]=28;
            }
            while(d!=0){
                left_time=month[mon-1];
                if(left_time>=d){
                    day=d;
                    d=0;
                }
                else{
                    d-=left_time;
                    if(mon<12)
                        mon++;
                    else{
                        mon=1;
                        year++;
                        if(is(year))
                            month[1]=29;
                        else
                            month[1]=28;
                    }
                }
            }
        }
        printf("%d-",year);
        if(mon<10)
            printf("0");
        printf("%d-",mon);
        if(day<10)
            printf("0");
        printf("%d\n",day);
    }
    return 0;
}

