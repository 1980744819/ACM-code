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
struct stu{
	double x;
	double y;
}a,b,t,bottle[100005];
double disa[100005],disb[100005],dist[100005];
double get_dis(stu c,stu d){
	return sqrt((c.x-d.x)*(c.x-d.x)+(c.y-d.y)*(c.y-d.y));
}
int main(){
	int i,j;
	int n;
	double sum;
	scanf("%lf %lf %lf %lf %lf %lf",&a.x,&a.y,&b.x,&b.y,&t.x,&t.y);
	//printf("%f %f %f %f %f %f\n",a.x,a.y,b.x,b.y,t.x,t.y);
	scanf("%d",&n);
	//printf("%d\n",n);
	sum=0;
	for(i=0;i<n;i++){
		scanf("%lf %lf",&bottle[i].x,&bottle[i].y);
		//printf("%f %f\n",bottle[i].x,bottle[i].y);
		dist[i]=get_dis(bottle[i],t);
		sum+=2*dist[i];
		disa[i]=get_dis(bottle[i],a);
		disb[i]=get_dis(bottle[i],b);
	}
	// for(i=0;i<n;i++){
	// 	printf("%f ",dist[i]);
	// }
	// printf("\n");
	// for(i=0;i<n;i++){
	// 	printf("%f ",disa[i]);
	// }
	// printf("\n");
	// for(i=0;i<n;i++){
	// 	printf("%f ",disb[i]);
	// }
	// printf("\n");
	// printf("%f\n",sum);
	double Mina=999999999999999,Minb=999999999999999,Minc=999999999999999;
	double tmp;
	for(i=0;i<n;i++){
		tmp=sum-dist[i]+disa[i];
		//printf("%f ",tmp);
		if(Mina>tmp){
			Mina=tmp;
		}
		tmp=sum-dist[i]+disb[i];
		//printf("%f\n",tmp);
		if(Mina>tmp){
			Mina=tmp;
		}
	}
	int pos=0;
	for(i=0;i<n;i++){
		tmp=sum-dist[i]+disa[i];
		if(Minb>tmp){
			Minb=tmp;
			pos=i;
		}
	}
	double tm=Minb;
	for(i=0;i<n;i++){
		if(i!=pos){
			tmp=tm-dist[i]+disb[i];
			if(Minb>tmp){
				Minb=tmp;
			}
		}
	}
	for(i=0;i<n;i++){
		tmp=sum-dist[i]+disb[i];
		if(Minc>tmp){
			Minc=tmp;
			pos=i;
		}
	}
	tm=Minc;
	for(i=0;i<n;i++){
		if(i!=pos){
			tmp=tm-dist[i]+disa[i];
			if(Minc>tmp){
				Minc=tmp;
			}
		}
	}
	double ans=min(Mina,min(Minb,Minc));
	printf("%.12f\n",ans);
    return 0;
}
