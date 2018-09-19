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
bool judge(int num){
	for(int i=2;i*i<=num;i++){
		if(num%i==0)
			return false;
	}
	return true;
}
int main(){
	int i,j;
	for(i=2;i<=1000;i++){
		if(judge(i))
			printf("%d,",i);
	}
    return 0;
}
