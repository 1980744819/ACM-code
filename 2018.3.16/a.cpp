#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;
const int maxn = 10000;
int main()
{
    freopen("test.txt", "r", stdin);
    // freopen("test.out", "w", stdout);
    vector<vector<int> >array;
    std::vector<int> v;
    int m,n;
    while(~scanf("%d %d",&m,&n)){
    	for(int i=0;i<m;i++){
    		v.clear();
    		for(int j=0;j<n;j++){
    			int num;
    			scanf("%d",&num);
    			v.push_back(num);
    		}
    		array.push_back(v);
    	}
    	int a=array.size();
    	int b=array[0].size();
    	printf("%d %d\n",a,b);
    	for(int i=0;i<a;i++){
    		for(int j=0;j<b;j++){
    			printf("%d ",array[i][j]);
    		}
    		printf("\n");
    	}
    }
    return 0;
}
