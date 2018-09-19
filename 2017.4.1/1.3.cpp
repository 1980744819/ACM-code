#include <cstdio>
#include <map>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		map<int,int> a;
		int n;
		scanf("%d",&n);
		int tmp;
		int res=1;
		for(int i=0;i<n;i++){
			scanf("%d",&tmp);
			if(a[tmp]>0){
				a.clear();
				res++;
			}
			a[tmp]=1;
		}
		printf("%d\n",res);
	}
	return 0;
}

