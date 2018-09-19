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
int main(){
	stack<char>st;
	int i,j;
	string ch;
	int flag;
	while(cin>>ch){
		i=0;
		flag=0;
		for(i=0;i<ch.size();i++){
			if(ch[i]=='('){
				st.push('(');
			}
			else if(ch[i]==')'){
				if(!st.empty())
					st.pop();
				else{
					flag=1;
					cout<<"NO"<<endl;
					break;
				}
			}
		}
		if(!flag){
			if(!st.empty()){
				cout<<"NO"<<endl;
			}
			else{
				cout<<"YES"<<endl;
			}
		}
		while(!st.empty()){
			st.pop();
		}
	}
    return 0;
}
