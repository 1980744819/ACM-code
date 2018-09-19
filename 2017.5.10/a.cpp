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
char a[100005];
int main(){
	int n,k;
	int i,j;
	int M;
	M=0;
	//printf("%d\n",'z'-'a');
	scanf("%d %d",&n,&k);
	scanf("%s",a);
	//puts(a);
	for(i=0;i<n;i++){
		M+=max('z'-a[i],a[i]-'a');
	}
	if(M<k){
		printf("-1\n");
		return 0;
	}
	int tmp;
	for(i=0;i<n;i++){
		if(k>0){
			if('z'-a[i]>a[i]-'a'){
				tmp='z'-a[i];
				if(k>=tmp){
					printf("z");
					k-=tmp;
				}
				else{
					printf("%c",a[i]+k);
					k=0;
				}
			}
			else{
				tmp=a[i]-'a';
				if(k>=tmp){
					printf("a");
					k-=tmp;
				}
				else{
					printf("%c",a[i]-k);
					k=0;
				}
			}
		}
		else{
			printf("%c",a[i]);
		}
	}
	printf("\n");
    return 0;
}
