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
#define ll long long
using namespace std;
const int maxn=10000;
class Date{
public:
	void setdate(int y,int m,int d){
		year=y;
		month=m;
		day=d;
	}
	int is_leap_year(){
		return year%4==0&&year%100!=0||year%400==0;
	}
	void print(){
		cout<<year<<'/'<<month<<'/'<<day<<endl;
	}
private:
	int year,month,day;
};
int main(){
	//freopen("test.txt","r",stdin);
	Date d1,d2,*pd=&d2;
	d1.setdate(2005,6,24);
	pd->setdate(2000,2,8);
	cout<<d1.is_leap_year()<<','<<d2.is_leap_year()<<endl;
	d1.print();
	d2.print();
    return 0;
}
