#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,e,f,x,y,i,k=0;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	scanf("%d:%d",&e,&f);
	x=e*60+f;
	y=x+b;
	for(i=300;i<=1439;i+=c)
	{
		if((i<y&&i+d>x)) k++;
	}
	cout<<k;


	return 0;
}
