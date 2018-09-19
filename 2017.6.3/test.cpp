#include<iostream>
#include<stdio.h>
#include<math.h>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	FILE *fp = fopen("D:\\4.in", "w+");
	if (fp == NULL)
		cout << 0 << endl;
	set<long long>st;
	long long da[1005];
	long long a,b,num,l;
	fprintf(fp,"100000\n");
	l=0;
	while(st.size()<100000){
		a=rand()*rand();
		//b=rand()%11;
		a<<=rand()%11;
		a>>=rand()%5;
		if(st.find(a)==st.end()&&st.size()<100000){
			cout<<a<<"	"<<st.size()<<endl;
			fprintf(fp,"%lld ",a);
			if(l<1000){
				da[l]=a;
				l++;
			}
			st.insert(a);
		}
	}
	fprintf(fp, "\n1000\n");
	for(int i=0;i<l;i++){
		fprintf(fp, "%lld ",da[i]);
	}
	fprintf(fp,"\n");
	st.clear();
	return 0;
}
