#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<cmath>
#define ff(i,x,y) for(int i=x;i<y;i++)
#define maxlen 100000+7

using namespace std;


double R, l, w;

int t;
double a, b;

int main()
{
	map<int> cc;
	//freopen("test.txt","r",stdin);
	scanf("%lf %lf %lf", &R, &l, &w);
	scanf("%d", &t);

	while(t--)
	{
		scanf("%lf %lf", &a, &b);

		//cout<<a<<endl;
		//cout<<b<<endl;

		double disdir1;
		double dispoint1;
		double disdir2;
		double dispoint2;

		double tana = tan(a);
		double sina = sin(a);

		double sinb = sin(b);
		double cosa = cos(a);
		double cosb = cos(b);

		//cout<<tana<<" "<<sina<<" "<<cosa<<" "<<sinb<<" "<<cosb<<endl;

		//return 0;

		double ax = -l;
		double ay = 0;
		//cout<<ax<<endl;
		//cout<<ay<<endl;
		double bx = -(l * cos(b));
		double by = l * sin(b) - w;
		double cx = -(l * cosa);
		double cy = l * sina;
		double atoux;
		double btoux;

		double ansa;
		double ansb;
		//disdir1 = abs((tana * ax + ay) / sqrt(1 + tana * tana));
		disdir1=l*sina;
		atoux = disdir1 * sina + ax;
		dispoint1 = sqrt((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy));
		//if(atoux >= cx && atoux <= 0)
		//{
			ansa = disdir1;
		//}
		//else
		//{
		//	ansa = dispoint1;
		//}



		//disdir2 = abs((tana * bx + by) / sqrt(1 + tana * tana));
		disdir2=w*cosb;
		btoux = disdir2 * sina + bx;
		dispoint2 = sqrt(bx * bx + by * by);

		/*
		if(btoux >= cx && btoux <= 0)
		{
			ansb = disdir2;
		}
		else
		{
			ansb = dispoint2;
		}*/
		ansb=w*sinb>=l?dispoint2:disdir2;

		 if(a>=1.5708)
		 {
        	ansa=l;
			//ansb=w*cosb;
			//ansb=dispoint2;
		 }

         if(b>=1.5708)
		 {
            ansb=-by;
		 }

		//cout<<ansa<<endl;
		//cout<<ansb<<endl;
        double ans=min(ansa,ansb);
        ans=min(ans,2*	R);
        ans=min(ans,w);

        printf("%.9f\n",ans/2);

	}

	return 0;
}