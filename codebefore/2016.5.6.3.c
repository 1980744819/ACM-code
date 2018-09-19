
 #include<cstdio>
int f[111111]={};
int n,k;int temp=1;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&f[i]);
	while(k>temp)
		k-=temp,temp++;
	printf("%d\n",f[k]);
}
