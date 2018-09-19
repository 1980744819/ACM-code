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
int n;
int a[100005],c[100005];
long long coun,k;
void merge(int a[],int first,int mid,int last,int c[]){
    int i,j;
    i=first,j=mid+1;
    int k=0;
    while(i<=mid||j<=last){
        if(j>last||(i<=mid&&a[i]<=a[j])){
            c[k]=a[i];
            i++;
            k++;
        }
        else{
            c[k]=a[j];
            k++;
            j++;
            coun+=mid-i+1;
        }
    }
    for(i=0;i<k;i++){
        a[first+i]=c[i];
    }
}
void mergesort(int a[],int first,int last,int c[]){
    if(last==first)
        return;
    int mid=(first+last)/2;
    mergesort(a,first,mid,c);
    mergesort(a,mid+1,last,c);
    merge(a,first,mid,last,c);
}

int main(){
    int i,j;
    while(cin>>n>>k){
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        coun=0;
        mergesort(a,0,n-1,c);
        if(k>=coun)
            cout<<"0"<<endl;
        else
            cout<<coun-k<<endl;
        memset(c,0,sizeof(c));
    }
    return 0;
}

