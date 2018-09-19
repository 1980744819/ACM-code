#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<set>
using namespace std;
int m,n;
int order[405],machine[21][21],Time[21][21];
bool schedule[21][10005];//ʱ����
int dur[21];//������һ�ν��е���ĩʱ��
int use_num[21];//�������е��ĸ�����
int ans;
int main(){
    int i,j,k;
    int t;
    int coun;
    int work_num;
    int step;
    int ma;//ʹ�õĻ���
    while(~scanf("%d%d",&m,&n)){
        for(i=1;i<=m*n;i++){
            scanf("%d",&order[i]);
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&machine[i][j]);
            }
        }
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                scanf("%d",&Time[i][j]);
            }
        }
        //printf("\n");
        ans=0;
        for(i=1;i<=m*n;i++){
            work_num=order[i];//���мӹ��Ĺ������
            use_num[work_num]++;
            step=use_num[work_num];//���мӹ��Ĺ�����Ž��е��Ĳ�����
            ma=machine[work_num][step];//���мӹ��Ĺ�����Ž��е��Ĳ�������ʹ�õĻ������
            t=Time[work_num][step];//���мӹ��Ĺ�����Ž��е��Ĳ���ı�������ʱ��
            coun=0;
            for(j=dur[work_num]+1;t>coun;j++){
                if(schedule[ma][j]==false){
                    coun++;
                }
                else{
                    coun=0;
                }
            }
            j--;
            ans=max(ans,j);
            dur[work_num]=j;
            for(k=j;t>0;k--){
                schedule[ma][k]=true;
                t--;
            }
            //printf("%d %d %d %d %d\n",work_num,step,ma,t,j);
        }
        printf("%d\n",ans);
        memset(dur,0,sizeof(dur));
        memset(use_num,0,sizeof(use_num));
        memset(schedule,false,sizeof(schedule));
    }
    return 0;
}
