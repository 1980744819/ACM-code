#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace::std;
struct lib{
    //int num;
    char name[35];
    int qua;
};
int main(){
    int n;
    while(~scanf("%d",&n)){
        int number;
        char nam[35];
        int qu;
        struct lib book[10005];
        while(n--){
            scanf("%d",&number);
            scanf("%s",nam);
            scanf("%d",&qu);
            strcpy(book[number].name,nam);
            book[number].qua=qu;
        }
        scanf("%d",&n);
        char op[10];
        while(n--){
            scanf("%s",op);
            scanf("%d",&number);
            scanf("%s",nam);
            //printf("%d %d%s\n",number,book[number].qua,book[number].name);
            if(strcmp(op,"borrow")==0){
                //printf("bbbb");
                if(book[number].qua>=1&&strcmp(book[number].name,nam)==0){
                    printf("right\n");
                    book[number].qua--;
                }
                else{
                    printf("wrong\n");
                }
            }
            else{
                if(strcmp(book[number].name,nam)==0){
                    printf("right\n");
                    book[number].qua++;
                }
                else{
                    printf("wrong\n");
                }
            }
        }
    }
    return 0;
}
