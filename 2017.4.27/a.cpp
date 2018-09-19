#include<stdio.h>//OJ--J行编辑问题 
#include<malloc.h> 
#include<cstdlib>
#include<cstring>
#include<stack>//栈的头文件 
using namespace std;
int main(){
	stack<char>sta;
	char c[100005];
	int i;
	int len;
	while(~scanf("%s",c)){
		len=strlen(c);
		for(i=0;i<len;i++){
				if(c[i]=='#'){
				sta.pop();
			}
			else if(c[i]=='@'){
				while(!sta.empty()){
					sta.pop();
				}
			}
			else{
				sta.push(c[i]);
			}
		}
		while(!sta.empty()){
			printf("%c",sta.top());
			sta.pop();
		}
	}
	return 0; 
}
