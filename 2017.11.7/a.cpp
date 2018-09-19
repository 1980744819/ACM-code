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
class Clock{
public:
	Clock(int newh,int newm,int news);
	~Clock();
	void SetTime(int NewH,int NewM,int NewS);
	void ShowTime();
private:
	int Hour,Minutes,Second;

};
Clock::Clock(int newh,int newm,int news){
	Hour=newh;
	Minutes=newm;
	Second=news;
	cout<<"Constructor called."<<endl;
}
Clock::~Clock(){
	cout<<"Desturctor called."<<endl;
}
void Clock::SetTime(int NewH,int NewM,int NewS){
	Hour=NewH;
	Minutes=NewM;
	Second=NewS;
}
void Clock::ShowTime(){
	cout<<Hour<<":"<<Minutes<<":"<<Second<<endl;
}
int main(){
	//freopen("test.txt","r",stdin);
	Clock c(0,0,0);
	c.ShowTime();
    return 0;
}
