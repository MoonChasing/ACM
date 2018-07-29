#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=350;
struct Node
{
    int start,end;
};
int n;
int vis[maxn];
Node a[maxn];
int cmp(Node a,Node b)
{
    if(a.end==b.end) return a.start<b.start;
    else return a.end<b.end;
}
int main()
{
    int ans;
    while(scanf("%d",&n)==1&&n)
    {
        ans=0;
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].start,&a[i].end);
        sort(a,a+n,cmp);
        for(int s=0;s<5;s++)
        {
            int tmp=0;
            memset(vis,0,sizeof(vis));
            for(int tm=s;tm<a[n-1].end;tm+=5)
            {
                for(int i=0;i<n;i++)
                {
                    if(vis[i]) continue;
                    if(tm<a[i].end&&tm>=a[i].start)
                    {
                        vis[i]=1;
                        tmp++;
                        break;
                    }
                }
            }
            ans=max(ans,tmp);
        }
        printf("%d\n",ans);
    }
    return 0;
}
