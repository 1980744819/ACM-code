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
class Point{
public:
	Point(int xx=0,int yy=0){
		x=xx;
		y=yy;
	}
	Point(Point& p);
	int get_x(){
		return x;
	}
	int get_y(){
		return y;
	}
	~Point();
private:
	int x,y;
};
Point::Point(Point &p){
	x=p.x;
	y=p.y;
	cout<<"Constructor called."<<endl;
}
Point::~Point(){
	cout<<"Desturctor called."<<endl;
}
void fun1(Point p){
	cout<<p.get_x()<<endl;
}
Point fun2(){
	Point A(1,2);
	return A;
}
int main(){
	//freopen("test.txt","r",stdin);
	Point A(1,2);
	fun1(A);
	Point B(A);
	cout<<B.get_x()<<endl;
	Point C;
	C=fun2();
    return 0;
}
