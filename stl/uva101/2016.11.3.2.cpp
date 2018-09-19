#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;
int n;
vector<int> pile[30];
void find_block(int a,int& i,int &j){
    for( i=0;i<n;i++){
        for( j=0;j<pile[i].size();j++){
            if(pile[i][j]==a)
                return;
        }
    }
}
void clear_above(int p,int h){
    for(int i=h+1;i<pile[p].size();i++){
        int b=pile[p][i];
        pile[b].push_back(b);
    }
    pile[p].resize(h+1);
}
void pile_onto(int p,int h,int p2){
    for(int i=h;i<pile[p].size();i++){
        pile[p2].push_back(pile[p][i]);
    }
    pile[p].resize(h);
}
void print(){
    for(int i=0;i<n;i++){
        printf("%d:",i);
        for(int j=0;j<pile[i].size();j++)
            printf(" %d",pile[i][j]);
        printf("\n");
    }
}
int main(){
    int a,b;
    cin>>n;
    string s1,s2;
    for(int i=0;i<n;i++)
        pile[i].push_back(i);
    while(cin>>s1>>a>>s2>>b){
        int pa,ha;
        int pb,hb;
        find_block(a,pa,ha);
        find_block(b,pb,hb);
        if(pa==pb)
            continue;
        if(s2=="onto") clear_above(pb,hb);
        if(s1=="move")clear_above(pa,ha);
        pile_onto(pa,ha,pb);
    }
    print();
    return 0;
}
