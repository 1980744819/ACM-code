#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int main(){
    char a[100005],b[100005];
    while(~scanf("%s",a)){
        scanf("%s",b);
        int lena=strlen(a);
        int lenb=strlen(b);
        int i,j;
        i=0;j=0;
        while(1){
            if(i==lena){
                printf("Yes\n");
                break;
            }
            else if(i<lena&&j==lenb){
                printf("No\n");
                break;
            }
            if(a[i]==b[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
    }
    return 0;
}
