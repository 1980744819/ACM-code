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
char s[10];//={"zero"，"","two","","four","","six","","","nine"};
//s[0]="zero";
int main(){
	int i,j;
	char ch[100010];
	int len;
	int n;
	int tmp;
	scanf("%d",&n);
	while(n--){
		scanf("%s",ch);
		len=strlen(ch);
		i=0;
		while(i<len){
			if(ch[i]=='0'||ch[i]=='2'||ch[i]=='4'||ch[i]=='6'||ch[i]=='9'){
				printf("%c",ch[i]);
				//i++;
			}
			else if(ch[i]=='z'){
				tmp=i;
				for(j=0;j<4;j++){
					s[j]=ch[tmp];
					tmp++;
				}
				s[j]='\0';
				//puts(s);
				if(strcmp(s,"zero")==0){
					printf("0");
				}
			}
			else if(ch[i]=='t'){
				tmp=i;
				for(j=0;j<3;j++){
					s[j]=ch[tmp];
					tmp++;
				}
				s[j]='\0';
				//puts(s);
				if(strcmp(s,"two")==0){
					printf("2");
				}
			}
			else if(ch[i]=='f'){
				tmp=i;
				for(j=0;j<4;j++){
					s[j]=ch[tmp];
					tmp++;
				}
				s[j]='\0';
				//puts(s);
				if(strcmp(s,"four")==0){
					printf("4");
				}
			}
			else if(ch[i]=='s'){
				tmp=i;
				for(j=0;j<3;j++){
					s[j]=ch[tmp];
					tmp++;
				}
				s[j]='\0';
				//puts(s);
				if(strcmp(s,"six")==0){
					printf("6");
				}
			}
			else if(ch[i]=='n'){
				tmp=i;
				for(j=0;j<4;j++){
					s[j]=ch[tmp];
					tmp++;
				}
				s[j]='\0';
				//puts(s);
				if(strcmp(s,"nine")==0){
					printf("9");
				}
			}
			i++;
		}
		printf("\n");
	}
    return 0;
}
