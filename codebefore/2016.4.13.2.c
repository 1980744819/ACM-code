#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include<math.h>
int q[14];
int cont=0;
void print(int n){
    int i,j;
    cont++;
    if(cont<=3){
        for(i=1;i<=n;i++){
            printf("%d ",q[i]);
        }
        printf("\n");
    }
}
int find(int i,int k){
    int j=1;
    while(j<i){
        if(q[j]==k||abs(j-i)==abs(q[j]-k))
            return 0;
        j++;
    }
    return 1;
}
void place(int k,int n){
    int j;
    if(k>n)
        print(n);
    else{
        for(j=1;j<=n;j++){
            if(find(k,j)){
                q[k]=j;
                place(k+1,n);
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    place(1,n);
    printf("%d\n",cont);
    return 0;
}

