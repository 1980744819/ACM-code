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
const float PI=3.14159;
const float FencePrice=35;
const float ConcretePrice=20;
class Circle{
private:
	float radius;
public:
	Circle(float r);
	float Circumfence()const;
	float Area()const;
};
Circle::Circle(float r){
	radius=r;
}
float Circle::Circumfence()const{
	return 2*PI*radius;
}
float Circle::Area()const{
	return PI*radius*radius;
}
int main(){
	//freopen("test.txt","r",stdin);

    return 0;
}
