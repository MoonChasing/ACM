#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
typedef long long LL;
const LL mod = 1e9+7;
const double eps = 1e-9;
const int inf = 0x3f3f3f3f;
const int maxn = 105;
const int MAXN = 1e5 + 100;
int fa[MAXN];
vector<int> ve[MAXN];
struct node
{
    int fa,num;
} lajibaidu[MAXN];
bool cmp(node a,node b)
{
    return a.num>b.num;
}
bool cmp1(node a,node b)
{
    return a.num<b.num;
}
int vis[MAXN];
signed  main()
{
    int i,j,k,n,m;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        fa[1] = 0;
        for(i = 2; i <= n; i ++)
        {
            scanf("%d",&fa[i]);
        }
        LL LaJiBaiDu = 0;
        LL BaiDuLaJi = 0;
        for(i = 1; i <= n; i++)
        {
            scanf("%d",&k);
            lajibaidu[i].num = k;
            lajibaidu[i].fa = fa[i];
        }
        sort(lajibaidu+1,lajibaidu+1+n,cmp);
        memset(vis,0,sizeof(vis));
        LaJiBaiDu = max(lajibaidu[1].num,0);
        vis[lajibaidu[1].fa] = 1;
        bool flag = 0;
        for(i = 2; i <= n; i++)
        {
            if(lajibaidu[i].num>0)
            {
                if(vis[lajibaidu[i].fa] < 2)
                {
                    if(vis[lajibaidu[i].fa] == 0)
                    {
                        LaJiBaiDu += lajibaidu[i].num;
                        vis[lajibaidu[i].fa]++;
                    }
                    else
                    {
                        if(!flag)
                        {
                            LaJiBaiDu += lajibaidu[i].num;
                            vis[lajibaidu[i].fa]++;
                            if(vis[lajibaidu[i].fa] == 2)
                                flag = 1;
                        }
                    }
                }
            }
        }
        flag = 0;
        memset(vis,0,sizeof(vis));
        sort(lajibaidu+1,lajibaidu+1+n,cmp1);
        BaiDuLaJi = min(0,lajibaidu[1].num);
        vis[lajibaidu[1].fa] = 1;
        for(i = 2; i <= n; i++)
        {
            if(lajibaidu[i].num<0)
            {
                if(vis[lajibaidu[i].fa] < 2)
                {
                    if(vis[lajibaidu[i].fa] == 0)
                    {
                        BaiDuLaJi += lajibaidu[i].num;
                        vis[lajibaidu[i].fa]++;
                    }
                    else
                    {
                        if(!flag)
                        {
                            BaiDuLaJi += lajibaidu[i].num;
                            vis[lajibaidu[i].fa]++;
                            if(vis[lajibaidu[i].fa] == 2)
                                flag = 1;
                        }
                    }
                }
            }
        }
        printf("%lld %lld\n",LaJiBaiDu,BaiDuLaJi);
    }
    return 0;
}
