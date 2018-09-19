#include <stdio.h>
#include <stdlib.h>
int num[361];
int machine[19][362];
int used[19], order[19][19];
int last[19];
int time[19][19];
int max[19];

int main(int argc, char **argv)
{
    int i, j, k, l;
    int m, n, count;
    int ans = 0;
    scanf("%d%d", &m, &n);
    for(i = 0; i < m * n; i++){
        scanf("%d", &num[i]);
        num[i]--;
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &order[i][j]);
            order[i][j]--;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &time[i][j]);
        }
    }
    for(i = 0; i < m * n; i++){
        k = order[num[i]][used[num[i]]];
        count = 0;
        for(j = last[num[i]]; count < time[num[i]][used[num[i]]]; j++){
            if(machine[k][j] == 0){
                count++;
            }else{
                count = 0;
            }
        }
        for(l = 1; l <= count; l++){
            machine[k][j - l] = 1;
        }
        last[num[i]] = j;
        used[num[i]]++;
        if(max[k] < j){
            max[k] = j;
        }
    }
    for(i = 0; i < m; i++){
        if(ans < max[i]){
            ans = max[i];
        }
    }
    printf("%d\n", ans);
    return 0;
}
