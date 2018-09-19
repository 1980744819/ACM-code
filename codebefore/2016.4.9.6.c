#include<stdio.h>
#include<string.h>
int jc(int i){
    int m=1;
    while(i!=0){
        m*=i;
        i--;
    }
    return m;
}
int main(){
    int i,j;
    printf("n e\n- -----------\n");
    double e=0;
    for(i=0;i<10;i++){
            e+=1./jc(i);
        if(i==1||i==0){
            printf("%d %1.f\n",i,e);
        }
        else if(i==2){
            printf("%d %1.1f\n",i,e);
        }
        else{
            printf("%d %1.9f\n",i,e);
        }
    }
    return 0;
}


