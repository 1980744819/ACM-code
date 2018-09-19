#include <iostream>
#define INF 0xffffff
using namespace std;

int main(){
    int m, n;
    cin >> n >> m;
    int a[105]={0};
    char b[105][55];
    a[0] = INF;
    for (int i = 1; i <= m; i ++)
        cin >> b[i];
    for (int i = 1; i <= m; i ++){
        for (int j = 0; j < n; j ++)
            for (int k = j + 1; k < n; k ++){
                if (b[i][j] > b[i][k])
                    a[i] ++;
            }
    }
    int p = 0;
    for (int i = 1; i <= m; i ++){
        for (int j = 1; j <= m; j ++){
            if (a[j] < a[p])
                p = j;
        }
        cout <<  b[p] << endl;
        a[p] = INF;
        p = 0;
    }
    return 0;
}

