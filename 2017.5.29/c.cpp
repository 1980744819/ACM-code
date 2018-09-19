#include<iostream>
using namespace std;
int main()
{
    int i,j;
    char s[4][4];
    cin>>s[0]>>s[1]>>s[2]>>s[3];
    int blag=0;
    for(i=0;i<4;i++){
        for(j=0;j<4;j++){
            if(s[i][j]=='.'){
                if(i>0&&s[i-1][j]=='x'&&i<3&&s[i+1][j]=='x')blag=1;
                if(j>0&&s[i][j-1]=='x'&&j<3&&s[i][j+1]=='x')blag=1;
                if(j>0&&i>0&&s[i-1][j-1]=='x'&&j<3&&i<3&&s[i+1][j+1]=='x')blag=1;
                if(j>0&&i>0&&j<3&&i<3&&s[i-1][j+1]=='x'&&s[i+1][j-1]=='x')blag=1;
                if(i>1&&s[i-1][j]=='x'&&s[i-2][j]=='x')blag=1;
                if(j>1&&s[i][j-1]=='x'&&s[i][j-2]=='x')blag=1;
                if(i<2&&s[i+1][j]=='x'&&s[i+2][j]=='x')blag=1;
                if(j<2&&s[i][j+1]=='x'&&s[i][j+2]=='x')blag=1;
                if(i>1&&j>1&&s[i-1][j-1]=='x'&&s[i-2][j-2]=='x')blag=1;
                if(i<2&&j<2&&s[i+1][j+1]=='x'&&s[i+2][j+2]=='x')blag=1;
                if(i>1&&j<2&&s[i-1][j+1]=='x'&&s[i-2][j+2]=='x')blag=1;
                if(i<2&&j>1&&s[i+1][j-1]=='x'&&s[i+2][j-2]=='x')blag=1;
            }
        }
    }
    if(blag)
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
    return 0;
}