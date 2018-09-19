#include <cstdio>  
#include <cstring>  
#include <vector>  
#include <set>  
#include <queue>  
#include <algorithm>  
using namespace std;  
 
queue<int> Q[300005];  
queue<pair<int,int> > time;  
bool vis[300005];  
int main()  
{  
    int n,q;  
    int op,num;  
    scanf ("%d %d",&n,&q);  
    int ant = 1;  
    int ans = 0;  
    while (q--)  
    {  
        scanf ("%d %d",&op,&num);  
        if (op == 1)  
        {  
            ans++;  
            Q[num].push(ant);  
            time.push(make_pair(ant,num));  
            ant++;  
        }  
        else if (op == 2)  
        {  
            while (!Q[num].empty())  
            {  
                vis[Q[num].front()] = true; 
                Q[num].pop();  
                ans--;   
            }  
        }  
        else  
        {  
            while (!time.empty() && time.front().first <= num)  
            {  
                if (!vis[time.front().first])       
                {  
                    Q[time.front().second].pop();  
                    ans--;  
                }  
                time.pop();  
            }  
        }  
        printf ("%d\n",ans);  
    }  
    return 0;  
}  