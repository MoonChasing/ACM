#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[66],vis[66];
int n,num,m;
bool p;
int cmp(int a,int b)
{
	return a>b;
}
void dfs(int st,int cur,int cnt)
{
	if(p||cnt==num)
	{
		p=true;
		return ;
	}
	for(int i=st;i<n;i++)
	{
		if(vis[i]||cur+a[i]>m)    //訪问过的木棍或者加上当前木棍长度后超过了目标长度，则跳过本次循环
			continue;
		if(i-1&&!vis[i-1]&&a[i]==a[i-1])    //若当前木棍和上一根木棍长度同样而且上一根木棍没用到，则跳过本次循环。
			continue;
		if(a[i]+cur==m)
		{
			vis[i]=1;
			dfs(0,0,cnt+1);
			vis[i]=0;
			return;				//循环里后面的值都在dfs中求过了。这里直接返回上一层
		}
		if(a[i]+cur<m)
		{
			vis[i]=1;
			dfs(i+1,a[i]+cur,cnt);
			vis[i]=0;
			if(cur==0)           //cur为0时,直接返回上一层
				return ;
		}
	}
}
int main()
{
	while(scanf("%d",&n)!=EOF&&n)
	{
		int sum=0;
		p=false;
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		sort(a,a+n,cmp);
		for(num=n;num>=1;num--)
		{
			if(sum%num||a[0]>sum/num)
				continue;
			m=sum/num;
			dfs(0,0,0);
			if(p)
				break;
		}
		printf("%d\n",m);
	}
	return 0;
}
