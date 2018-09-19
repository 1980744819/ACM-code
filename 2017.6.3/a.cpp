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
set<int>st;
void inst(int num){
	if(st.find(num)==st.end()){
		st.insert(num);
	}
	else{
		st.erase(num);
		inst(num+1);
	}
}
int main(){
	int i,j;
	int n;
	int num;
	while(~scanf("%d",&n)){
		while(n--){
			scanf("%d",&num);
			// if(st.find(num)==st.end()){
			// 	st.insert(num);
			// }
			// else{
			// 	st.erase(num);
			// 	inst(num+1);
			// }
			inst(num);
		}
		printf("%d\n",st.size());
		st.clear();
	}
    return 0;
}
