#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
using namespace std;

struct interval{
    int begin;
    int end;
};

bool cmp(interval x,interval y){
    return x.end < y.end;
}


int main(){
    //freopen("a.txt", "r", stdin);
    int m;
    cin >> m;

    while (m--){
        int n;
        cin >> n;

        vector<interval> vec(n);

        for (int i = 0; i < n;i++){
            int a;
            cin >> vec[i].begin >> a;
            vec[i].end=vec[i].begin+a;
        }

        sort(vec.begin(),vec.end(),cmp);

        int end = -1;
        int res = 0;
        for (int i = 0; i < n;i++){
            if (end<=vec[i].begin){
                res++;
                end = vec[i].end;
            }
        }

        cout << res << endl;

    }
    return 0;
}
