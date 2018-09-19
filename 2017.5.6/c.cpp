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
struct stu
{
    int ch;
    int math;
    int en;
    int id;
    int sum;
}student[305];
void change(int i,int j){
	struct stu tmp;
    tmp.sum=student[i].sum;
    tmp.id=student[i].id;
    tmp.ch=student[i].ch;
    tmp.math=student[i].math;
    tmp.en=student[i].en;
    student[i].sum=student[j].sum;
    student[i].id=student[j].id;
    student[i].ch=student[j].ch;
    student[i].math=student[j].math;
    student[i].en=student[i].en;
    student[j].sum=tmp.sum;
    student[j].id=tmp.id;
    student[j].ch=tmp.ch;
    student[j].math=tmp.math;
    student[j].en=tmp.en;
}    
int main(){

	int i,j;
	int n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d %d %d",&student[i].ch,&student[i].math,&student[i].en);
        student[i].sum=student[i].ch+student[i].math+student[i].en;
        student[i].id=i;
	}
	for(i=0;i<n;i++){
		for(j=0;j<i;j++){
			if(student[i].sum>student[j].sum){
				change(i,j);
			}
			else if(student[i].sum==student[j].sum){
				if(student[i].ch>student[j].ch){
					change(i,j);
				}
				else  if(student[i].ch==student[j].ch){
					if(student[i].id<student[j].id){
						change(i,j);
					}
				}

			}
		}
	}
	for(i=0;i<5;i++){
		printf("%d %d\n",student[i].id+1,student[i].sum);
	}
    return 0;
}
