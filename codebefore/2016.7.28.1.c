#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
char s[35];
int main(){
    int kase;
    scanf("%d",&kase);
    int time=0;
    int i;
    for(i=1;i<=kase;i++){
            getchar();
        gets(s);
        printf("Case #%d: ",i);
        //puts(s);
        if(strcmp("Cleveland Cavaliers",s)==0)time=1;
        else if(strcmp("Golden State Warriors",s)==0)time=2;
        else if(strcmp("San Antonio Spurs",s)==0)time=5;
        else if(strcmp("Miami Heat",s)==0)time=3;
        else if(strcmp("Dallas Mavericks",s)==0)time=1;
        else if(strcmp("L.A. Lakers",s)==0)time=11;
        else if(strcmp("Boston Celtics",s)==0)time=17;
        else if(strcmp("Detroit Pistons",s)==0)time=3;
        else if(strcmp("Chicago Bulls",s)==0)time=6;
        else if(strcmp("Houston Rockets",s)==0)time=2;
        else if(strcmp("Philadelphia 76ers",s)==0)time=2;
        else if(strcmp("Seattle Sonics",s)==0)time=1;
        else if(strcmp("Washington Bullets",s)==0)time=1;
        else if(strcmp("Portland Trail Blazers",s)==0)time=1;
        else if(strcmp("New York Knicks",s)==0)time=2;
        else if(strcmp("Milwaukee Bucks",s)==0)time=1;
        else if(strcmp("St. Louis Hawks",s)==0)time=1;
        else if(strcmp("Syracuse Nats",s)==0)time=1;
        else if(strcmp("Minneapolis Lakers",s)==0)time=5;
        else if(strcmp("Rochester Royals",s)==0)time=1;
        else if(strcmp("Baltimore Bullets",s)==0)time=1;
        else if(strcmp("Philadelphia Warriors",s)==0)time=2;
        else time=0;
        memset(s,'\0',sizeof(s));
        printf("%d\n",time);
    }
    return 0;
}
