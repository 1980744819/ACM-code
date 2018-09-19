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
	int num;
	struct stu next*;
}node;
struct stu *createnode(){
	struct stu *p=(node *)malloc(sizeof(node));
	p->next=NULL;
	return p;
}
int main(){
    return 0;
}
