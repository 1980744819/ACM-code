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
	string s;
	int n,t;
	int i,j;
	cin>>n>>t;
	cin>>s;
	i=0;
	int len=0;
	while(s[i]!='.'){
		i++;
	}
	while(i<n&&s[i]<'5'){
		i++;
	}
	if(i==n){
		cout<<s<<endl;
		return 0;
	}
	i--;
	len=0;
	while(t>0){
		if(s[i]=='.'){
			i--;
			len=i;
			while(s[i]>=0&&s[i]=='9'){
				s[i]='0';
				i--;
			}
			if(i==-1){
				cout<<"1";
			}
			else{
				s[i]++;
			}
			break;
		}
		else{
			s[i]++;
		}
		if(s[i]<'5'){
			len=i;
			break;
		}
		else{
			len=i;
			i--;
		}
		t--;
	}
	//cout<<len<<endl;
	for(i=0;i<=len;i++){
		cout<<s[i];
	}
	cout<<endl;
    return 0;
}
