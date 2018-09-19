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
	char a[2000],b[2000];
	int n;
	int i,j;
	while(~scanf("%s %s %d",a,b,&n)){
		for(i=0;i<n-1;i++){
			printf("%c",a[i]);
		}
		for(j=0;b[j]!='\0';j++){
			printf("%c",b[j]);
		}
		for(i=n-1;a[i]!='\0';i++){
			printf("%c",a[i]);
		}
		printf("\n");
	}
    return 0;
}
